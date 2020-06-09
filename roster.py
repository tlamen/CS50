import sys
import cs50
import sqlite3

def main(arg1):
    # Connect with the .db file and make a cursor
    housename = arg1.lower()

    houses = ["gryffindor", "hufflepuff", "ravenclaw", "slytherin"]
    if housename in houses:
        sqlite_file = "students.db"
        con = sqlite3.connect(sqlite_file)
        cur = con.cursor()

        #Store all data from selected house into houseroster
        cur.execute('SELECT first, middle, last, birth FROM students WHERE lower(house) = "{}" ORDER BY last, first;'.format(housename))
        houseroster = cur.fetchall()

        for row in houseroster:
            if row[1] == None:
                print("{} {}, born {}".format(row[0], row[2], row[3]))
            else:
                print("{} {} {}, born {}".format(row[0], row[1], row[2], row[3]))
        return 0
    else:
        print("Select a valide hogwarts house: gryffindor, hufflepuff, ravenclaw (the best), or slytherin")
        return 1

if len(sys.argv) == 2:
    argument1 = sys.argv[1]
    main(argument1)
else:
    print("Usage: python roster.py Hogwarts_house")
