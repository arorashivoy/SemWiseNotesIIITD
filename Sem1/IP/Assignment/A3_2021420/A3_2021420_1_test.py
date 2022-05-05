# CSE 101
# Assignment 3
# Problem 1 - To Test the Solution
#
# By - Shivoy Arora
# Roll No - 2021420
import A3_2021420_1


def test_matmul(A, B, true_C):
    """ To test the multiplication of two matrices
        Args:
            A: first matrix
            B: second matrix
            true_C: true resultant matrix
        Returns:
            True, if the multiplication of two matrices is correct, else False
    """
    C = A3_2021420_1.matmul(A, B)

    try:
        assert C == true_C, "Answer not correct"

        return True
    except AssertionError:
        return False


def test_scale(x, y, z, sx, sy, sz, true_x, true_y, true_z):
    """ To test the scaling of the coordinates of the 3D shape
        Args:
            x: x coordinate
            y: y coordinate
            z: z coordinate
            sx: scaling factor of x coordinate
            sy: scaling factor of y coordinate
            sz: scaling factor of z coordinate
            true_x: true scaled x coordinate
            true_y: true scaled y coordinate
            true_z: true scaled z coordinate
        Returns:
            True, if the scaling of the coordinates of the 3D shape is correct, else False
    """

    for i in range(len(x)):
        x_, y_, z_ = A3_2021420_1.scale(x[i], y[i], z[i], sx, sy, sz)

        try:
            assert x_ == true_x[i] and y_ == true_y[i] and z_ == true_z[i], "Answer not correct"
        except AssertionError:
            return False

    else:
        return True


def test_translate(x, y, z, tx, ty, tz, true_x, true_y, true_z):
    """ To test the translation of the coordinates of the 3D shape
        Args:
            x: x coordinate
            y: y coordinate
            z: z coordinate
            tx: translating factor of x coordinate
            ty: translating factor of y coordinate
            tz: translating factor of z coordinate
            true_x: true translated x coordinate
            true_y: true translated y coordinate
            true_z: true translated z coordinate
        Returns:
            True, if the translation of the coordinates of the 3D shape is correct, else False
    """
    for i in range(len(x)):
        x_, y_, z_ = A3_2021420_1.translate(x[i], y[i], z[i], tx, ty, tz)

        try:
            assert x_ == true_x[i] and y_ == true_y[i] and z_ == true_z[i], "Answer not correct"
        except AssertionError:
            return False

    else:
        return True


def test_rotate(x, y, z, axis, angle, true_x, true_y, true_z):
    """ To test the rotation of the coordinates of the 3D shape
        Args:
            x: x coordinate
            y: y coordinate
            z: z coordinate
            axis: axis of rotation
            angle: angle of rotation
            true_x: true rotated x coordinate
            true_y: true rotated y coordinate
            true_z: true rotated z coordinate
        Returns:
            True, if the rotation of the coordinates of the 3D shape is correct, else False
    """
    for i in range(len(x)):
        x_, y_, z_ = A3_2021420_1.rotate(x[i], y[i], z[i], axis, angle)

        try:
            assert x_ == true_x[i] and y_ == true_y[i] and z_ == true_z[i], "Answer not correct"
        except AssertionError:
            return False

    else:
        return True


def getTrueCoordinates(n):
    """ To get the true coordinates of the 3D shape
        Args:
            n: number of coordinates
        Returns:
            true_x: true x coordinate
            true_y: true y coordinate
            true_z: true z coordinate
    """
    while True:
        true_x = input(
            "Enter true_x coordinate of the shape with spaces between each value: ")
        true_y = input(
            "Enter true_y coordinate of the shape with spaces between each value: ")
        true_z = input(
            "Enter true_z coordinate of the shape with spaces between each value: ")

        true_x = [float(i) for i in true_x.split()]
        true_y = [float(i) for i in true_y.split()]
        true_z = [float(i) for i in true_z.split()]

        if len(true_x) == n and len(true_y) == n and len(true_z) == n:
            break
        else:
            print(
                "Number of elements in true_x, true_y ,true_z should be same, Try again...")
            print()

    return true_x, true_y, true_z


def getMatrix():
    """ To input a matrix
        Returns:
            A: matrix
    """
    n = int(input("Enter number of rows and columns of the matrix: "))

    A = []
    for i in range(n):
        row = input(
            "Enter row {} of the matrix with spaces between each value: ".format(i + 1))
        row = [float(i) for i in row.split()]
        A.append(row)

    return A


""" Main Function """
if __name__ == "__main__":

    print("Press 1: To check the sample cases")
    print("Press 2: To input your own case")

    choice = int(input("Enter your choice: "))
    # Test cases

    print()

    if choice == 1:
        # Matmul
        A = [[1, 2, 3], [1, 2, 3], [1, 2, 3]]
        B = [[4, 5, 6], [4, 5, 6], [4, 5, 6]]

        true_C = [[24, 30, 36], [24, 30, 36], [24, 30, 36]]

        print("Testing matmul")
        val = test_matmul(A, B, true_C)

        if val:
            print("Test case 1 passed")
        else:
            print("Test case 1 failed")

        print()

        x = [0, 1, 1, 0, 0, 1, 1, 0]
        y = [0, 0, 1, 1, 0, 0, 1, 1]
        z = [0, 0, 0, 0, 1, 1, 1, 1]

        # Scale
        sx = 2
        sy = 2
        sz = 2

        true_x = [0, 2, 2, 0, 0, 2, 2, 0]
        true_y = [0, 0, 2, 2, 0, 0, 2, 2]
        true_z = [0, 0, 0, 0, 2, 2, 2, 2]

        print("Testing scaling")
        val = test_scale(x, y, z, sx, sy, sz, true_x, true_y, true_z)

        if val:
            print("Test case 2 passed")
        else:
            print("Test case 2 failed")

        print()

        # Translate

        tx = 2
        ty = 0
        tz = 0

        true_x = [2, 3, 3, 2, 2, 3, 3, 2]
        true_y = [0, 0, 1, 1, 0, 0, 1, 1]
        true_z = [0, 0, 0, 0, 1, 1, 1, 1]

        val = test_translate(x, y, z, tx, ty, tz, true_x, true_y, true_z)

        print("Testing translation")
        if val:
            print("Test case 3 passed")
        else:
            print("Test case 3 failed")

        print()

        # Rotate

        axis = "x"
        angle = 90

        true_x = [0, 1, 1, 0, 0, 1, 1, 0]
        true_y = [0, 0, 0, 0, -1, -1, -1, -1]
        true_z = [0, 0, 1, 1, 0, 0, 1, 1]

        print("Testing rotation")
        val = test_rotate(x, y, z, axis, angle, true_x, true_y, true_z)

        if val:
            print("Test case 4 passed")
        else:
            print("Test case 4 failed")

    else:
        # User provided test cases
        #
        # Getting original coordinates
        while True:
            n = int(input("Enter the number of vertices: "))
            x = input(
                "Enter x coordinate of the shape with spaces between each value: ")
            y = input(
                "Enter y coordinate of the shape with spaces between each value: ")
            z = input(
                "Enter z coordinate of the shape with spaces between each value: ")

            x = [float(i) for i in x.split()]
            y = [float(i) for i in y.split()]
            z = [float(i) for i in z.split()]

            if len(x) == n and len(y) == n and len(z) == n:
                break
            else:
                print("Number of elements in x, y , z should be same, Try again...")
                print()

        # Getting query
        print("Enter Queries in the follwing format:-")
        print("For Scaling:     S sx sy sz, where sx, sy, sz are the scaling factor of the respective axis")
        print("For Translating: T tx ty tz, where tz, ty, tz are the amount to be translated respectively")
        print("For Rotating:    R axis θ, where axis is x, y, z and θ is in degrees")
        print("For matmul:      M")
        print("\n")

        transformation = input("Enter transformation: ").split()

        # For scaling
        if transformation[0].strip().upper() == "S":
            # Getting True Answer
            true_x, true_y, true_z = getTrueCoordinates(n)

            val = test_scale(x, y, z, float(transformation[1]), float(
                transformation[2]), float(transformation[3]), true_x, true_y, true_z)

            if val:
                print("Test case passed")
            else:
                print("Test case failed")

        # For translating
        elif transformation[0].strip().upper() == "T":
            # Getting true answer
            true_x, true_y, true_z = getTrueCoordinates(n)

            val = test_translate(x, y, z, float(transformation[1]), float(
                transformation[2]), float(transformation[3]), true_x, true_y, true_z)

            if val:
                print("Test case passed")
            else:
                print("Test case failed")

        # For rotation
        elif transformation[0].strip().upper() == "R":
            # Getting true answer
            true_x, true_y, true_z = getTrueCoordinates(n)

            val = test_rotate(x, y, z, transformation[1], float(
                transformation[2]), true_x, true_y, true_z)

            if val:
                print("Test case passed")
            else:
                print("Test case failed")

        # For matmul
        elif transformation[0].strip().upper() == "M":
            print("Enter Matrix A")
            A = getMatrix()
            print("\nEnter Matrix B")
            B = getMatrix()

            print("\nEnter Matrix true_C")
            true_C = getMatrix()

            val = test_matmul(A, B, true_C)

            if val:
                print("Test case passed")
            else:
                print("Test case failed")
