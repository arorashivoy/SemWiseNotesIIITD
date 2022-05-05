# CSE 101
# Assignment 1
# Problem 2
#
# By - Shivoy Arora
# Roll No - 2021420

n = int(input("Enter number of student: "))
print()

for _ in range(n):
    # Menu
    print("Press 1: For Square")
    print("Press 2: For Rectangle")
    print("Press 3: For Rhombus")
    print("Press 4: For Parallelogram")
    print("Press 5: For Circle")
    print("Press 6: For Cube")
    print("Press 7: For Cuboid")
    print("Press 8: For Right Circular Cone")
    print("Press 9: For Hemisphere")
    print("Press 10: For Sphere")
    print("Press 11: For Solid cylinder")
    print("Press 12: For Hollow cylinder")

    # Getting choice
    while True:
        shape = int(input("\nEnter choice: "))
        if shape not in [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]:
            print("Enter right choice\n")
        else:
            break

    # Square
    if shape == 1:
        s = float(input("Enter side: "))

        print("Perimeter:", 4*s)
        print("Area:", s**2)

    # Rectangle
    elif shape == 2:
        l = float(input("Enter length: "))
        b = float(input("Enter breadth: "))

        print("Perimeter:", 2*(l+b))
        print("Area:", l*b)

    # Rhombus
    elif shape == 3:
        a = float(input("Enter side: "))
        d1 = float(input("Enter Diagonal 1"))
        d2 = float(input("Enter Diagonal 2"))

        print("Perimeter:", 4*s)
        print("Area", d1*d2/2)

    # Parallelogram
    elif shape == 4:
        l = float(input("Enter length: "))
        b = float(input("Enter breadth: "))
        h = float(input("Enter height: "))

        print("Perimeter:", 2*(l+b))
        print("Area:", l*h)

    # Circle
    elif shape == 5:
        r = float(input("Enter radius: "))

        print("Perimeter:", 2*3.14*r)
        print("Area:", 3.14*(r**2))

    # Cube
    elif shape == 6:
        s = float(input("Enter side: "))

        print("CSA:", 4*(s**2))
        print("TSA:", 6*(s**2))
        print("Volume:", s**3)

    # Cuboid
    elif shape == 7:
        l = float(input("Enter length: "))
        b = float(input("Enter breadth: "))
        h = float(input("Enter height: "))

        print("CSA:", 2*(l+b)*h)
        print("TSA:", 2*(l*b+b*h+h*l))
        print("Volume:", l*b*h)

    # Rt. Circular cone
    elif shape == 8:
        l = float(input("Enter slant height: "))
        r = float(input("Enter radius: "))
        h = float(input("Enter height: "))

        print("CSA:", 3.14*r*l)
        print("TSA:", 3.14*r*(r+l))
        print("Volume:", 3.14*(r**2)*h/3)

    # hemisphere
    elif shape == 9:
        r = float(input("Enter radius: "))

        print("CSA:", 2*3.14*(r**2))
        print("TSA:", 3*3.14*(r**2))
        print("Volume:", 2*3.14*(r**3)/3)

    # sphere
    elif shape == 10:
        r = float(input("Enter radius: "))

        print("TSA:", 4*3.14*(r**2))
        print("Volume:", 4*3.14*(r**3)/3)

    # solid cylinder
    elif shape == 11:
        r = float(input("Enter radius: "))
        h = float(input("Enter height: "))

        print("CSA:", 2*3.14*r*h)
        print("TSA:", 2*3.14*r*(r+h))
        print("Volume:", 3.14*(r**2)*h)

    # hollow cylinder
    else:
        r1 = float(input("Enter outer radius: "))
        r2 = float(input("Enter inner radius: "))
        h = float(input("Enter height: "))

        print("CSA:", 2*3.14*(r1+r2)*h)
        print("TSA:", 2*3.14*(r1+r2)*h + 2*3.14*(r1**2-r2**2))
        print("Volume:", 3.14*(r1**2-r2**2)*h)

    print("\n\n")
