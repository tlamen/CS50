import sys
import csv
import cs50

def main(arg1):
    # Create database by opening and closing an empty file first
    open(f"students.db", "w").close()
    db = cs50.SQL("sqlite:///students.db")

    db.execute("CREATE TABLE students (first TEXT, middle TEXT, last TEXT, house TEXT, birth INTEGER)")


    with open(arg1) as csv_file:
        csv_reader = csv.DictReader(csv_file, delimiter=',')

        for row in csv_reader:
            s = row["name"]
            l = s.split()
            if len(l) == 2:
                db.execute("INSERT INTO students (first, last, house, birth) VALUES(?, ?, ?, ?)",
                l[0], l[1], row["house"], row["birth"])
            else:
                db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                l[0], l[1], l[2], row["house"], row["birth"])


if len(sys.argv) == 2:
    argument1 = sys.argv[1]
    main(argument1)
else:
    print("Usage: python import.py csv_file")
