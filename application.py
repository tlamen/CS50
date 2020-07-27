import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    # Get user's cash amount, saved as cashed
    cash = db.execute("SELECT cash FROM users WHERE id = :id;", id = session["user_id"])
    dinheiro = cash[0]
    cashed = dinheiro["cash"]

    # Get all stocks user has, saved as stocksDB
    stocksDB = db.execute("SELECT * FROM stocks WHERE ownerId = :id;", id = session["user_id"])

    # Get number of shares from each stock, displayes in dictyonary symbols = { 'stockSymbol' : number_of_shares}
    symbols = {}
    for stock in stocksDB:
        if stock["stockSymbol"] not in symbols:
            symbols[stock["stockSymbol"]] = 1
        elif stock["stockSymbol"] in symbols:
            symbols[stock["stockSymbol"]] += 1

    # Get stocks price, in dictyonary lookings = { 'stockSymbol' : price }
    lookings = {}
    for symbol in symbols:
        looking = lookup(symbol)
        lookings[looking["symbol"]] = looking["price"]

    # Get stocks total price, in dictyonary prices = { 'stockSymbol' : totalPrice }
    prices = {}
    for symbol in symbols:
        prices[symbol] =  float(symbols[symbol] * lookings[symbol])

    # Easiest relation between name and symbol, saved as names = { 'stockSymbol' : 'stockName' }
    names = {}
    for stocks in stocksDB:
        x = stocks["stockSymbol"]
        names[x] = stocks["stockName"]
    print(names)

    return render_template("index.html", cashed = cashed, names = names, symbols = symbols, lookings = lookings, prices = prices)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":

        # Ensure symbol was submitted
        if not request.form.get("symbol"):
            return apology("must provide symbol", 403)

        # Ensure shares was submitted
        if not request.form.get("shares"):
            return apology("must provide shares", 403)

        number = int(request.form.get("shares"))
        if number < 1:
            return apology("Must buy at least 1 share")

        # Get user's cash amount, saved as cashed
        cash = db.execute("SELECT cash FROM users WHERE id = :id;", id = session["user_id"])
        dinheiro = cash[0]
        cashed = dinheiro["cash"]

        # Get looking dictionary with information about the stock and check if it exists. Then check if user has cash enough to buy it and update its cash after buying it
        looking = lookup(request.form.get("symbol"))
        if looking == None:
            return apology("Check if you typed an existing symbol", 403)
        else:
            totalPrice = float(looking["price"] * number)
            if cashed < totalPrice:
                return apology("Too poor lol")
            else:
                cashed = cashed - totalPrice
                db.execute("UPDATE users SET cash = :cash WHERE id = :id;", cash = cashed, id = session["user_id"])

                # Add the bought stock to the database
                db.execute("INSERT INTO history (ownerId, stockSymbol, type, number, price) VALUES (:id, :symbol, :buy, :number, :price);", id = session["user_id"], symbol = looking["symbol"], buy = "buy", number = number, price = totalPrice)
                for x in range(number):
                    db.execute("INSERT INTO stocks (stockName, stockSymbol, ownerId) VALUES (:name, :symbol, :owner);", name = looking["name"], symbol = looking["symbol"], owner = session["user_id"])
                    # Redirect user to homepage:
                return redirect("/")
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    database = db.execute("SELECT * FROM history WHERE ownerId = :id;", id = session["user_id"])
    print(database)
    return render_template("history.html", database = database)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("symbol"):
            return apology("must provide symbol", 403)

        # Use lookup function to look for stock symbols
        looking = lookup(request.form.get("symbol"))

        # Check function return
        if looking == None:
            return apology("Couldn't find symbol", 403)
        else:
            return render_template("quoted.html", looking=looking)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Ensure confirm password was submitted
        elif not request.form.get("confirm password"):
            return apology("must confirm password", 403)

        # Query database for username and check if it's unique
        rows = db.execute("SELECT username FROM users WHERE username = :username",
                          username=request.form.get("username"))
        if rows:
            return apology("Username already in use. Choose another one")

        # Check if confirmed password matches password
        Rpassword = request.form.get("password")
        Rcpassword = request.form.get("confirm password")
        if Rpassword != Rcpassword:
            return apology("Confirmed password must match password")

        # Insert user into db
        rows = db.execute("INSERT INTO users (username, hash) VALUES (:username, :password)", username = request.form.get("username"), password = (generate_password_hash(request.form.get("password"),method='pbkdf2:sha256', salt_length=8)))

        # Redirect user to home page
        return redirect("/")

    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":
        # Ensure user provides stock symbol, and save it as variable
        if not request.form.get("symbol"):
            return apology("must sell something.")
        else:
            symbol = request.form.get("symbol")

        # Ensure user provides number of stocks, and save it as variable
        if not request.form.get("number"):
            return apology("must sell at least 1 stock.")
        else:
            number = int(request.form.get("number"))

        # Get stocks database
        stocks = db.execute("SELECT * FROM stocks WHERE ownerId = :id", id = session["user_id"])

        # Ensure user has at least one share of provided symbol
        counter = 0
        for stock in stocks:
            if stock["stockSymbol"] == symbol:
                counter = counter + 1
                break
        if counter == 0:
            return apology("You don't have any shares of this stock")

        # If user provides a number greater than the number of shares they have, sell all their stocks
        counter1 = 0
        for stock in stocks:
            if stock["stockSymbol"] == symbol:
                counter1 = counter1 + 1
        if number > counter1:
                number = counter1

        # Get user's cash amount, saved as cashed
        cash = db.execute("SELECT cash FROM users WHERE id = :id;", id = session["user_id"])
        dinheiro = cash[0]
        cashed = dinheiro["cash"]

        # Get shares' price, stored as price
        looking = lookup(symbol)
        price = looking["price"]

        #Add money to users account
        money = number * price
        cashed = cashed + money
        db.execute("UPDATE users SET cash = :cash WHERE id = :id;", cash = cashed, id = session["user_id"])

        # Delete shares from stocks DB
        # Syntax error near TOP
        db.execute("DELETE FROM stocks WHERE ownerId = :id AND stockSymbol = :symbol LIMIT :x;", x = number, id = session["user_id"], symbol = symbol)
        db.execute("INSERT INTO history (ownerId, stockSymbol, type, number, price) VALUES (:id, :symbol, :sell, :number, :price);", id = session["user_id"], symbol = symbol, sell = "sell", number = number, price = money)

        return redirect("/")
    else:
        return render_template("sell.html")

@app.route("/add", methods=["GET", "POST"])
@login_required
def add():
    """Add more money (personal touch)"""
    if request.method == "POST":
        # Ensure user provides cash amount
        if not request.form.get("cash"):
            return apology("need to add something")
        else:
            money = float(request.form.get("cash"))

        # Update user database, by geting users current cash and adding it to amount provided
        cash = db.execute("SELECT cash FROM users WHERE id = :id;", id = session["user_id"])
        dinheiro = cash[0]
        cashed = dinheiro["cash"]
        amount = cashed + money
        db.execute("UPDATE users SET cash = :amount WHERE id = :id;", amount = amount, id = session["user_id"])

        # Add to history
        db.execute("INSERT INTO history (ownerId, stockSymbol, type, number, price) VALUES  (:id, :symbol, :add, :number, :price);", id = session["user_id"], symbol = "-",  add = "add", number = "-", price = money)

        return redirect("/")
    else:
        return render_template("add.html")


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
