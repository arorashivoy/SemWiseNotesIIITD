# CSE 101
# Assignment 2
# Problem 6
#
# By - Shivoy Arora
# Roll No - 2021420

# Inputting matrix
n = int(input("Enter the size of nxn square matrix: "))

matrix = []
for i in range(n):
    while True:
        a = input("Enter row {} of matrix: ".format(i+1)).split()

        if len(a) == n:
            matrix.append(a)
            break
        else:
            print("Row must contanin {} elements".format(n))
            print("Try Again...\n")

while True:
    # Menu
    print("Press 1: For Normal transversal")
    print("Press 2: For Alternative transversal")
    print("Press 3: For Spiral transversal")
    print("Press 4: For Boundary transversal")
    print("Press 5: For Diagonal transversal from right to left")
    print("Press 6: For Diagonal transversal from left to right")
    print("Press 7: To quit")
    print()

    ops = int(input("Enter your choice: "))

    # Normal
    if ops == 1:
        for i in range(n):
            for j in range(n):
                print(matrix[i][j], end=" ")

    # Alternative
    elif ops == 2:
        for i in range(0, n, 2):
            for j in range(n):
                print(matrix[i][j], end=" ")
            if i+1 < n:
                for j in range(n-1, -1, -1):
                    print(matrix[i+1][j], end=" ")

    # Spiral
    elif ops == 3:
        transMatrix = [i.copy() for i in matrix]

        while transMatrix != []:
            # top
            if transMatrix != []:
                print(" ".join(transMatrix.pop(0)), end=" ")

            # right
            if transMatrix != []:
                for i in range(len(transMatrix)):
                    print(transMatrix[i].pop(), end=" ")

            # bottom
            if transMatrix != []:
                print(" ".join(transMatrix.pop()[::-1]), end=" ")
            # left
            if transMatrix != []:
                for i in range(len(transMatrix)-1, -1, -1):
                    print(transMatrix[i].pop(0), end=" ")

    # Boundary
    elif ops == 4:
        transMatrix = [i.copy() for i in matrix]

        # top
        if transMatrix != []:
            print(" ".join(transMatrix.pop(0)), end=" ")

        # right
        if transMatrix != []:
            for i in range(len(transMatrix)):
                print(transMatrix[i].pop(), end=" ")

        # bottom
        if transMatrix != []:
            print(" ".join(transMatrix.pop()[::-1]), end=" ")

        # left
        if transMatrix != []:
            for i in range(len(transMatrix)-1, -1, -1):
                print(transMatrix[i].pop(0), end=" ")

    # Diagonal right to left
    elif ops == 5:
        for j in range(n):
            for i in range(j+1):
                print(matrix[i][j-i], end=" ")

        for i in range(n):
            for j in range(n-1, i, -1):
                print(matrix[i-j][j], end=" ")

    # Diagonal left to right
    elif ops == 6:
        for j in range(n-1, -1, -1):
            for i in range(n-j):
                print(matrix[i][j+i], end=" ")

        for i in range(1, n):
            for j in range(n-i):
                print(matrix[i+j][j], end=" ")

    # Quit
    elif ops == 7:
        break

    print("\n")
