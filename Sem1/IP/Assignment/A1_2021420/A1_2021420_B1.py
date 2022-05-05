# CSE 101
# Assignment 1
# Bonus Problem 1
#
# By - Shivoy Arora
# Roll No - 2021420

# Getting items prices
item1 = int(input("Enter price of Item 1: "))
item2 = int(input("Enter price of Item 2: "))
item3 = int(input("Enter price of Item 3: "))

print("<", "-"*78, ">\n", sep="")

# Getting discounts of combos
print("Discount Details\n")
combo1 = int(input("Enter discound (in percentage) for the 1st saver combo: "))
combo2 = int(input("Enter discound (in percentage) for the 2nd saver combo: "))
combo3 = int(input("Enter discound (in percentage) for the 3rd saver combo: "))

print("<", "-"*78, ">\n", sep="")

# Getting contact number
while True:
    contactNo = int(input("Enter your contact number: "))

    if len("{}".format(contactNo)) != 10:
        print("Enter a valid 10 digit contact number\n")

    else:
        break

print("The resulting catalogue is:")

# The catalogue
print("*"*80)
print("*"*80)
print("Delhi Days")
print("R-Block, Model Town 3\nDelhi: 110009")
print("*"*80)

print("Item\t\t Price(per pack)")
print("-"*16, "-"*16)
print("Item 1\t\t", item1)
print("Item 2\t\t", item2)
print("Item 3\t\t", item3)
print("ComboPack 1\t", (item1+item2)*(1-combo1/100))
print("ComboPack 2\t", (item1+item3)*(1-combo2/100))
print("ComboPack 3\t", (item3+item2)*(1-combo3/100))
print("Super Saver\t", (item1+item2+item3)*(1-0.28))

print("*"*80)
print("*"*80)
print()
print("For more details, contact here: 9990286245")
