# CSE 101
# Assignment 1
# Problem 3
#
# By - Shivoy Arora
# Roll No - 2021420

while True:
    degree = int(input("Enter degree of the polynomial: "))

    if degree > 0 and degree <= 3:
        break
    else:
        print("Degree of the polynomial must be less than 3")

""" List of all the coefficients """
coeff = []
for i in range(degree):
    a = int(input("Enter Coefficient {}: ".format(i+1)))

    coeff += [a]
a = int(input("Enter constant term: "))
coeff += [a]

lowBound = int(input("Enter Lower bound: "))
upBound = int(input("Enter Upper bound: "))
steps = int(input("Enter steps in which x varies: "))

print()
print("-"*40)
for x in range(lowBound, upBound+1, steps):

    # Calculating the value of the polynomial for x
    ans = 0
    for j in range(len(coeff)):
        ans += (coeff[j] * (x**(degree - j)))

    print("|", "*"*ans, sep="")
