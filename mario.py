from cs50 import get_int

def main():
    h = get_positive_int()
    c = 1
    original = h
    while h > 0:
        print(" " * (original - c), end = "")
        print("#" * c, end = "")
        print("  ", end = "")
        print("#" * c)
        h = h - 1
        c = c + 1

def get_positive_int():
    while True:
        n = get_int("Height: ")
        if n > 0 and n < 9:
            break
        else:
            print("Height needs to be between 1 and 8")
    return n

main()