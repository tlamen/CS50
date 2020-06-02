import sys
import csv
from array import *


def main(arg1, arg2):
    lSTR = []  # List of single list of STRs in order, with lSTR[0][0] == 'name' (not used)
    lNAMES = []  # List with the names of the suspects, with [0] position not used (line below)
    lNAMES.append(0)
    lCOUNTER = []  # List of lists, each one contains counter for each name (info in csv file). [0] position not used (line below)
    lCOUNTER.append(0)
    # Read out all the information needed in the csv file
    with open(arg1) as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=',')
        line_count = 0
        for row in csv_reader:
            if line_count == 0:
                lSTR.append(row)
                line_count += 1
            else:
                lNAMES.append(row[0])
                for i in range(len(row)):
                    lCOUNTER.append([])
                    if i > 0:
                        lCOUNTER[line_count].append(row[i])
                line_count += 1

    # open txt file and read DNA sequence
    file = open(arg2, "r")
    s = ""
    for c in file:
        s = s + c
    file.close()
    lTXTCOUNTER = []

    # search for STRs
    position = 0  # Saves position in string s where the for loop is reading
    counter1 = 0  # (mutable variable) Saves number of consecutive STRs after c char
    maior = 0  # Saves biggest amount of consecutive STRs in the entire s string (final variable to compare)
    counter2 = 0
    for n in lSTR[0]:
        counter2 += 1
    for i in range(counter2):
        if i > 0:
            for c in s:
                if c == lSTR[0][i][0]:
                    str_length = len(lSTR[0][i])
                    if (position + str_length) < len(s):
                        Ts = s[position:(position + str_length)]
                        if Ts == lSTR[0][i]:
                            counter1 += 1
                            j = 2
                            while j < len(s):
                                Ts = s[(position + str_length * (j-1)):(position + str_length * j)]
                                if Ts == lSTR[0][i]:
                                    counter1 += 1
                                    j += 1
                                else:
                                    j = len(s)
                            if counter1 > maior:
                                maior = counter1
                        counter1 = 0
                position += 1
            position = 0
            lTXTCOUNTER.append(str(maior))
            maior = 0

    # print guilty
    counter3 = 0
    for lista in range(line_count):
        if lCOUNTER[lista] == lTXTCOUNTER:
            print(lNAMES[lista])
            counter3 += 1

    if counter3 == 0:
        print("No match")


if len(sys.argv) == 3:
    argument1 = sys.argv[1]
    argument2 = sys.argv[2]
    main(argument1, argument2)
else:
    print("Usage: python dna.py data.csv sequence.txt")