# main function (f cs50 library)
def main():
    #get input and set variables
    s = input("Text: ")
    letters = 0.0
    words = 1.0
    sentences = 0.0
    # get number of letters, sentences and words
    for a in s:
        if (a.isalpha()) == True:
            letters += 1.0
        if a == ' ':
            words += 1.0
        if a == '.' or a == '?' or a == '!':
            sentences += 1.0
    if sentences == 0.0:
        sentences = 1.0

    # set values for equation
    ele = 100 * letters / words
    esse = 100 * sentences / words
    index = 0.0588 * ele - 0.296 * esse - 15.8
    rounded = round(index)

    # check text grades
    if index < 1:
        print("Before grade 1")
    if index >= 1 and index <= 16:
        print("Grade " + str(rounded))
    if index > 16:
        print("Grade 16+")


# call main function
main()