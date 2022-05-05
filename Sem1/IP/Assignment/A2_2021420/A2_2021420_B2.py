# CSE 101
# Assignment 2
# Bonus Problem 2
#
# By - Shivoy Arora
# Roll No - 2021420

p, q = [int(i) for i in input().split()]
m, n = [int(i) for i in input().split()]

skyscrapers = [None]*n

# inputting skyline
for i in range(m):
    line = input()

    for j in range(len(line)):
        if line[j] == "1" and (not skyscrapers[j]):
            skyscrapers[j] = m-i

# Calculating reputation
dojaDog = 0
DJSnake = 0

owner = [None]*n
notBought = skyscrapers.copy()

for year in range(n):
    maxHeight = max(notBought)
    maxIndex = notBought.index(maxHeight)

    # DJ Snake buys it
    if year % 2:
        DJSnake += q*maxHeight
        owner[maxIndex] = "S"

    # Doja Dog buys it
    else:
        dojaDog += p*maxHeight
        owner[maxIndex] = "D"

    notBought[maxIndex] = 0

    p += 1
    q += 1

# Output
print("\n")
print(dojaDog, DJSnake)

print()

for i in range(m):
    for j in range(n):
        if m-i <= skyscrapers[j]:
            print(owner[j], end="")
        else:
            print("0", end="")

    print()
