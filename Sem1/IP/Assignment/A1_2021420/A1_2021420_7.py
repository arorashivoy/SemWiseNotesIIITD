# CSE 101
# Assignment 1
# Problem 7
#
# By - Shivoy Arora
# Roll No - 2021420

def calculate_area(l, a, b, d):
    """ To calculate the area under the graph of a function
        Args: 
            l: list of exponents of the polynomial with coefficients as 1
            a: lower limit of the integral
            b: upper limit of the integral
            d: common difference in sum terms
        Returns: Sum of the area under the graph of the funtion calculated using
                 Simpson's 1/3 algorithm
    """

    integralFn = 0
    for i in range(a, b, d):

        fnLow = 0
        fnUp = 0
        fnMid = 0

        # Calculating value of the functions
        for j in l:
            fnLow += i**j
            fnUp += (i+d)**j
            fnMid += ((2*i + d)/2)**j

        integralFn += (d/6) * (fnLow + 4*fnMid + fnUp)

    return integralFn


""" Main Function """
n = int(input("Enter number of terms: "))

exponents = []
for i in range(n):
    a = float(input("Enter power of term {}: ".format(i+1)))
    exponents += [a]

while True:
    a = int(input("Enter lower limit: "))
    b = int(input("Enter upper limit: "))
    d = int(input("Enter common difference in sum terms: "))

    if (b-a) % d != 0:
        print("(b-a) must be divisible by d\n")

        redo = input("Enter q to quit or anyother key to continue ")

        if redo == "q":
            exit()

        print("\n")

    else:
        break

print(calculate_area(exponents, a, b, d))
