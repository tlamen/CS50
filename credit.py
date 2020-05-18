#Main function
def main():

    #Get input and set counter variables
    x = input("Number: ")
    counter = 0

    #if number is too small, the number is invalid
    for c in x:
        if (c.isnumeric()) == True:
            counter += 1
    if counter < 12:
        print("INVALID")
        return 1

    #get first number and check if it's possible to be a card
    primeiro = x[0]
    #VISA check
    if primeiro == '4':
        print("VISA")
        return 0
    #AMEX check
    if primeiro == '3':
        segundo = x[1]
        if segundo == '4' or segundo == '7':
            print("AMEX")
            return 0
    #MASTERCARD check
    if primeiro == '5':
        segundo = x[1]
        if segundo == '1' or segundo == '2' or segundo == '3' or segundo == '4' or segundo == '5':
            print("MASTERCARD")
            return 0

    #Call invalid if none of the checks succed
    print("INVALID")
    return 1

#Calling main fuction
main()



