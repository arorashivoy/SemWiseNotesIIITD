# CSE 101
# Assignment 1
# Bonus Problem 2
#
# By - Shivoy Arora
# Roll No - 2021420
from math import sqrt


def convStringCoords(vector):
    """ Converting a vector string to a list of the coordinates
        Args:
            vector: a vector string in the form <x,y,z>

        Returns: list of the vector [x,y,z]
    """
    coords = []
    coord = ""

    for i in vector:
        if i == "<":
            continue
        elif i == ",":
            coords.append(float(coord))
            coord = ""
        elif i == ">":
            continue
        elif i == " ":
            continue
        else:
            coord += i

    coords.append(float(coord))
    return coords


""" Main Function """
e = input("Enter origin of the ray (in the form of <ex,ey,ez>): ")
d = input("Enter direction of the ray (in the form of <dx,dy,dz>): ")

e = convStringCoords(e)
d = convStringCoords(d)

print()

x0 = float(input("Enter the x coordinate of the center of the sphere: "))
y0 = float(input("Enter the y coordinate of the center of the sphere: "))
z0 = float(input("Enter the z coordinate of the center of the sphere: "))
r = float(input("Enter the radius of the sphere: "))

# Getting coefficient of the equation of the line and the sphere
a = d[0]**2 + d[1]**2 + d[2]**2
b = 2*(d[0]*(e[0]-x0) + d[1]*(e[1]-y0) + d[2]*(e[2]-z0))
c = (e[0]-x0)**2 + (e[1]-y0)**2 + (e[1]-z0)**2 - r**2

# Finding sol of the line and the sphere
discriminant = b**2 - 4*a*c

if discriminant < 0:
    print("The ray will not intersect the sphere")
elif discriminant == 0:
    t = -b/(2*a)

    if t >= 0 and t <= 1000:
        print("The line will intersect the sphere at point ({}, {}, {})".format(
            round(e[0]+t*d[0], 2), round(e[1]+t*d[1], 2), round(e[2]+t*d[2], 2)
        ))
    else:
        print("The ray will not intersect the sphere")
else:
    t1 = (-b-sqrt(discriminant))/(2*a)
    t2 = (-b+sqrt(discriminant))/(2*a)

    if t1 <= 1000 and t1 >= 0 and t2 <= 1000 and t2 >= 0:
        print("The line will intersect the sphere at points ({}, {}, {}) and ({}, {}, {})".format(
            round(e[0]+t1*d[0], 2), round(e[1]+t1 *
                                          d[1], 2), round(e[2]+t1*d[2], 2),
            round(e[0]+t2*d[0], 2), round(e[1]+t2 *
                                          d[1], 2), round(e[2]+t2*d[2], 2)
        ))
    elif t1 <= 1000 and t1 >= 0:
        print("The line will intersect the sphere at point ({}, {}, {})".format(
            round(e[0]+t1*d[0], 2), round(e[1]+t1 *
                                          d[1], 2), round(e[2]+t1*d[2], 2)
        ))
    elif t2 <= 1000 and t2 >= 0:
        print("The line will intersect the sphere at point ({}, {}, {})".format(
            round(e[0]+t1*d[0], 2), round(e[1]+t1 *
                                          d[1], 2), round(e[2]+t1*d[2], 2)
        ))
    else:
        print("The ray will not intersect the sphere")
