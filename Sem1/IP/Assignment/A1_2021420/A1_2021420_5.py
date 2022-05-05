# CSE 101
# Assignment 1
# Problem 5
#
# By - Shivoy Arora
# Roll No - 2021420

def getReverse(n):
    """ To get the reverse of a non-negative number
        Args:
            n: a non-negative int
        Returns: reverse of number n
    """

    rev = 0
    while n != 0:
        rev = rev*10 + n % 10
        n //= 10

    return rev


def checkPalindrome(n):
    """ Check if the number is a palindrome 
        Args:
            n: a non-negative int
        Returns: True if n is a palindrome, else False
    """

    if n == getReverse(n):
        return True
    else:
        return False


def checkNarcissistic(n):
    """ Check if the number is narcissistic
        Args:
            n: a non-negative int
        Returns: True if n is narcissistic, else False
    """

    lenNum = len("{}".format(n))

    sumOfPower = 0
    for pow in range(1, lenNum+1):
        sumOfPower += ((n % (10**pow))//(10**(pow-1)))**lenNum

    if sumOfPower == n:
        return True
    else:
        return False


def findDigitSum(n):
    """ Find sum of the digits of n
        Args:
            n: a non-negative int
        Returns: sum of the digits of n
    """

    digitSum = 0
    while n != 0:
        digitSum += n % 10
        n //= 10

    return digitSum


def findSquareDigitSum(n):
    """ Find sum of the squares of the digits of n
        Args:
            n: a non-negative int
        Returns: sum of the squares of the digits of n 
    """

    digitSqSum = 0
    while n != 0:
        digitSqSum += (n % 10)**2
        n //= 10

    return digitSqSum


""" Main Function """
# Menu options
print("Press 1: To get reverse")
print("Press 2: To check palindrome ")
print("Press 3: To check narcissistic ")
print("Press 4: To find sum of the digits ")
print("Press 5: To find dum of swuare of the digits ")

# Getting choice
print()
while True:
    ops = int(input("Enter your choice: "))

    if ops in [1, 2, 3, 4, 5]:
        break
    else:
        print("Please enter a valid choice\n")

n = float(input("Enter a non-nagative number: "))

# Calling apt functions
if ops == 1:
    print(getReverse(n))
elif ops == 2:
    print(checkPalindrome(n))
elif ops == 3:
    print(checkNarcissistic(n))
elif ops == 4:
    print(findDigitSum(n))
else:
    print(findSquareDigitSum(n))
