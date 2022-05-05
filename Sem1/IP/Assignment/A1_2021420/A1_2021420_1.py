# CSE 101
# Assignment 1
# Problem 1
#
# By - Shivoy Arora
# Roll No - 2021420

# Printing menu items
print("Press 1: For 'Right-angled triangle' ")
print("Press 2: For 'Isosceles triangle' ")
print("Press 3: For 'Kite' ")
print("Press 4: For 'Half Kite'")
print("Press 5: For 'X'")

# Getting the pattern
while True:
    pattern = int(input("Enter the menu Number "))

    if pattern not in [1, 2, 3, 4, 5]:
        print("Enter correct option\n\n")
    else:
        break

# Getting value of n
while True:
    n = int(input("\nEnter n: "))

    # Since n must always be even in option 2,3,5
    if pattern in [2, 3, 5] and n % 2 == 1:
        print("n Should be even\n")
    else:
        break

# Right-angled Triangle
if pattern == 1:
    for i in range(1, n+1):
        for j in range(1, i+1):
            print(j, end=" ")
        print()

# Isosceles triangle
elif pattern == 2:
    for i in range(1, n+1):
        print("  "*(n-i+1), end="")

        for j in range(1, 2*i):
            print(j, end=" ")
        print()

# Kite
elif pattern == 3:
    for i in range(1, n+1):
        print("  "*(n-i+1), end="")

        for j in range(1, 2*i):
            print(j, end=" ")
        print()
    for i in range(n-1, 0, -1):
        print("  "*(n-i+1), end="")

        for j in range(1, 2*i):
            print(j, end=" ")
        print()

# Half kite
elif pattern == 4:
    for i in range(1, n+1):
        for j in range(1, i+1):
            print(j, end=" ")
        print()

    for i in range(n-1, 0, -1):
        for j in range(1, i+1):
            print(j, end=" ")
        print()

# X
else:
    for i in range(n, 0, -1):
        print("  "*(n-i+1), end="")

        for j in range(1, 2*i):
            print(j, end=" ")
        print()

    for i in range(2, n+1):
        print("  "*(n-i+1), end="")

        for j in range(1, 2*i):
            print(j, end=" ")
        print()
