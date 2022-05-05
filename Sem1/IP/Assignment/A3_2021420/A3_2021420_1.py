# CSE 101
# Assignment 3
# Problem 1 - finding the solution
# Test cases are in the A3_2021420_1_test.py file
#
# By - Shivoy Arora
# Roll No - 2021420
from math import cos, sin, radians


def matmul(A, B):
    """ To multiply the two matrices
        Args:
            A: first matrix
            B: second matrix
        Returns:
            C: resultant matrix
    """
    C = [[0 for _ in range(len(A[0]))] for _ in range(len(A))]

    for i in range(len(A)):
        for j in range(len(A[0])):
            for k in range(len(A[0])):
                C[i][j] += A[i][k] * B[k][j]
    return C


def scale(x, y, z, sx, sy, sz):
    """ To scale the coordinates of the 3D shape
        Args:
            x: x coordinate
            y: y coordinate
            z: z coordinate
            sx: scaling factor of x coordinate
            sy: scaling factor of y coordinate
            sz: scaling factor of z coordinate
        Returns:
            x_: scaled x coordinate
            y_: scaled y coordinate
            z_: scaled z coordinate
    """

    x_ = x * float(sx)
    y_ = y * float(sy)
    z_ = z * float(sz)

    return x_, y_, z_


def translate(x, y, z, tx, ty, tz):
    """ To translate the coordinates of the 3D shape
        Args:
            x: x coordinate
            y: y coordinate
            z: z coordinate
            tx: translating factor of x coordinate
            ty: translating factor of y coordinate
            tz: translating factor of z coordinate
        Returns:
            x_: translated x coordinate
            y_: translated y coordinate
            z_: translated z coordinate
    """

    x_ = x + float(tx)
    y_ = y + float(ty)
    z_ = z + float(tz)

    return x_, y_, z_


def rotate(x, y, z, axis, angle):
    """ To rotate the coordinates of the 3D shape
        Args:
            x: x coordinate
            y: y coordinate
            z: z coordinate
            axis:   The axis around which the shape is rotated
            angle:  The angle with which the shape is rotated (in degrees)
        Returns:
            x_: rotated x coordinate
            y_: rotated y coordinate
            z_: rotated z coordinate
    """

    angle = radians(float(angle))

    # z axis
    if axis.strip().lower() == "z":
        x_ = round(cos(angle)*x - sin(angle)*y, 2)
        y_ = round(sin(angle)*x + cos(angle)*y, 2)
        z_ = z

    # x axis
    elif axis.strip().lower() == "x":
        x_ = x
        y_ = round(cos(angle)*y - sin(angle)*z, 2)
        z_ = round(sin(angle)*y + cos(angle)*z, 2)

    # y axis
    elif axis.strip().lower() == "y":
        x_ = round(sin(angle)*z + cos(angle)*x, 2)
        y_ = y
        z_ = round(cos(angle)*z - sin(angle)*x, 2)

    return x_, y_, z_
