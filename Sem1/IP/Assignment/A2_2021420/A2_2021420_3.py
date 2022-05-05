# CSE 101
# Assignment 2
# Problem 3
#
# By - Shivoy Arora
# Roll No - 2021420

def getInput(A: str, B: str):
    """ To get if the operation is in A to B or B to A
        Args:
            A: Radix 1
            B: Radix 2
        Return:
            True, if A to B else False
    """
    print("Press 1: For {} to {}".format(A, B))
    print("Press 2: For {} to {}".format(B, A))
    print()

    while True:
        option = int(input("Enter Choice: "))
        if option == 1:
            order = True
            break
        elif option == 2:
            order = False
            break
        else:
            print("Enter a vaild option...Try Again!")

    num = input("Enter the number in radix {}: ".format(
                A if order else B))

    return order, num


def checkRadix(num: str, radix: int):
    """ To check if Number entered is of valid Radix
        Args:
            num: The enetered number in string
            radix: radix to which the number belong in int
        Returns:
            True, if number belongs to the radix else False
    """
    for i in num:
        if i.isdigit():
            if int(i) >= radix:
                return False
        else:
            if ord(i.upper()) - 55 >= radix:
                return False
    else:
        return True


def decimalBinary(num: str, order: bool):
    """ To convert Decimal to Binary and vice-versa
        Args:
            num: The number to be converted in string
            order: True for Int to Bin else, Bin to Int
        Returns:
            Number after changing to the other radix
    """
    # Int to Bin
    if order:
        newNum = ""
        num = int(num)
        while num != 0:
            newNum = str(num % 2) + newNum
            num //= 2
    # Bin to Int
    else:
        newNum = 0
        for i in range(len(num)):
            newNum += int(num[-(i+1)])*(2**i)

        newNum = str(newNum)

    return newNum


def decimalHexa(num: str, order: bool):
    """ To convert Decimal to Hexadecimal and vice-versa
        Args:
            num: The number to be converted in string
            order: True for Int to Hexa else, Hexa to Int
        Returns:
            Number after changing to the other radix
    """
    # Int to Hexa
    if order:
        newNum = ""
        num = int(num)
        while num != 0:
            digit = num % 16
            if digit > 9:
                digit = chr(digit+55)

            newNum = str(digit) + newNum
            num //= 16
    # Hexa to Int
    else:
        newNum = 0
        for i in range(len(num)):
            digit = num[-(i+1)]
            if digit.isalpha():
                digit = ord(digit.upper()) - 55

            newNum += int(digit)*(16**i)

        newNum = str(newNum)

    return newNum


def decimalOctal(num: str, order: bool):
    """ To convert Decimal to Octal and vice-versa
        Args:
            num: The number to be converted in string
            order: True for Int to Octal else, Octal to Int
        Returns:
            Number after changing to the other radix
    """
    # Int to Octal
    if order:
        newNum = ""
        num = int(num)
        while num != 0:
            digit = num % 8

            newNum = str(digit) + newNum
            num //= 8
    # Octal to Int
    else:
        newNum = 0
        for i in range(len(num)):
            digit = num[-(i+1)]

            newNum += int(digit)*(8**i)

        newNum = str(newNum)

    return newNum


def binHexa(num: str, order: bool):
    """ To convert Binary to Hexadecimal and vice-versa
        Args:
            num: The number to be converted in string
            order: True for Bin to Hexa else, Hexa to Bin
        Returns:
            Number after changing to the other radix
    """

    # Binary to Hexa
    if order:
        binToHexa = {"0000": "0", "0001": "1", "0010": "2", "0011": "3", "0100": "4", "0101": "5", "0110": "6", "0111": "7",
                     "1000": "8", "1001": "9", "1010": "A", "1011": "B", "1100": "C", "1101": "D", "1110": "E", "1111": "F"}

        num = "0"*(4 - len(num) % 4) + num
        newNum = ""

        for i in range(0, len(num), 4):
            newNum += binToHexa[num[i:i+4]]

    # Hexa to Bin
    else:
        hexaToBin = {"0": "0000", "1": "0001", "2": "0010", "3": "0011", "4": "0100", "5": "0101", "6": "0110", "7": "0111",
                     "8": "1000", "9": "1001", "A": "1010", "B": "1011", "C": "1100", "D": "1101", "E": "1110", "F": "1111"}

        newNum = ""
        for i in num:
            newNum += hexaToBin[i.upper()]

    return newNum


def binOctal(num: str, order: bool):
    """ To convert Binary to Octal and vice-versa
        Args:
            num: The number to be converted in string
            order: True for Bin to octal else, octal to Bin
        Returns:
            Number after changing to the other radix
    """

    # Binary to Hexa
    if order:
        binToOctal = {"000": "0", "001": "1", "010": "2",
                      "011": "3", "100": "4", "101": "5", "110": "6", "111": "7"}

        num = "0"*(3 - len(num) % 3) + num
        newNum = ""

        for i in range(0, len(num), 3):
            newNum += binToOctal[num[i:i+3]]

    # Hexa to Bin
    else:
        octalToBin = {"0": "000", "1": "001", "2": "010",
                      "3": "011", "4": "100", "5": "101", "6": "110", "7": "111"}

        newNum = ""
        for i in num:
            newNum += octalToBin[i.upper()]

    return newNum


def hexaOctal(num: str, order: bool):
    """ To convert Hexadecimal to Octal and vice-versa
        Args:
            num: The number to be converted in string
            order: True for Hexa to octal else, octal to hexa
        Returns:
            Number after changing to the other radix
    """
    # Hexa to Octal
    if order:
        return AToB(num, 16, 8)
    # Octal to Hexa
    else:
        return AToB(num, 8, 16)


def AToB(num: str, A: int, B: int):
    """ To convert a number from radix A to B
        Args:
            num: given number in radix A in string
            A: base of the radix A 
            B: base of the radix B
        Returns:
            the given number in radix B
    """
    # From base A to base 10
    mag = 0
    for i in range(len(num)):
        digit = num[-(i+1)]
        if digit.isalpha():
            digit = ord(digit.upper()) - 55

        mag += int(digit)*(A**i)

    # From base 10 to B
    newNum = ""
    while mag != 0:
        digit = mag % B
        if digit > 9:
            digit = chr(digit+55)

        newNum = str(digit) + newNum
        mag //= B

    return newNum


""" Main Function """
if __name__ == "__main__":

    while True:
        # Menu
        print("Press 1: To convert Decimal to Binary and vice-versa")
        print("Press 2: To convert Decimal to Hexadecimal and vice-versa")
        print("Press 3: To convert Decimal to Octal and vice-versa")
        print("Press 4: To convert Binary to Hexadeciaml and vice-versa")
        print("Press 5: To convert Binary to Octal and vice-versa")
        print("Press 6: To convert Hexadecimal to Octal and vice-versa")
        print("Press 7: To convert Convert a number with radix A to B")
        print("Press 8: To quit")
        print()

        ops = int(input("Enter Choice: "))

        # Decimal to Binary
        if ops == 1:
            order, num = getInput("Decimal", "Binary")

            if checkRadix(num, 10 if order else 2):
                print("Number in radix {} is".format(
                    "Binary" if order else "Decimal"), decimalBinary(num, order))
            else:
                print("Number entered does not belong to the given radix")
                print("Try Again...")

        # Decimal to Hexadecimal
        elif ops == 2:
            order, num = getInput("Decimal", "Hexadecimal")

            if checkRadix(num, 10 if order else 16):
                print("Number in radix {} is".format(
                    "Hexadecimal" if order else "Decimal"), decimalHexa(num, order))
            else:
                print("Number entered does not belong to the given radix")
                print("Try Again...")

        # Decimal to Octal
        elif ops == 3:
            order, num = getInput("Decimal", "Octal")

            if checkRadix(num, 10 if order else 8):
                print("Number in radix {} is".format(
                    "Octal" if order else "Decimal"), decimalOctal(num, order))
            else:
                print("Number entered does not belong to the given radix")
                print("Try Again...")

        # Binary to Hexadecimal
        elif ops == 4:
            order, num = getInput("Binary", "Hexadecimal")

            if checkRadix(num, 2 if order else 16):
                print("Number in radix {} is".format(
                    "Hexadecimal" if order else "Binary"), binHexa(num, order))
            else:
                print("Number entered does not belong to the given radix")
                print("Try Again...")

        # Binary to Octal
        elif ops == 5:
            order, num = getInput("Binary", "Octal")

            if checkRadix(num, 2 if order else 8):
                print("Number in radix {} is".format(
                    "Octal" if order else "Binary"), binOctal(num, order))
            else:
                print("Number entered does not belong to the given radix")
                print("Try Again...")

        elif ops == 6:
            order, num = getInput("Hexadecimal", "Octal")

            if checkRadix(num, 16 if order else 8):
                print("Number in radix {} is".format(
                    "Octal" if order else "Hexadecimal"), hexaOctal(num, order))
            else:
                print("Number entered does not belong to the given radix")
                print("Try Again...")

        # A to B
        elif ops == 7:
            A = int(input("Enter Base of the first number: "))
            B = int(input("Enter Base of the second number: "))

            num = input("Enter the number in radix {}: ".format(A))

            if checkRadix(num, A):
                print("Number in radix {} is".format(B), AToB(num, A, B))
            else:
                print("Number entered does not belong to the given radix")
                print("Try Again...")

        # To Quit
        elif ops == 8:
            break
        else:
            print("Enter a vaild ops...Try Again!")
            print("\n")

        print()
