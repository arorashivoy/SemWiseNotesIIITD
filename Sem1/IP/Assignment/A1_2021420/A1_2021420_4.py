# CSE 101
# Assignment 1
# Problem 4
#
# By - Shivoy Arora
# Roll No - 2021420

# For Fn = (b1 and not b1)
print("Fn = (b1 and not b1)")

for b1 in [True, False]:
    Fn = (b1 and not b1)

    # Fn becomes true
    if Fn:
        print("Satisfiable")
        print(b1)

        break
# The loop isn't broken
else:
    print("Unsatisfiable")

print()

# For Fn = (b1 or b2) and (b2 or not b3)
print("Fn = (b1 or b2) and (b2 or not b3)")

for b1 in [True, False]:
    for b2 in [True, False]:
        for b3 in [True, False]:
            Fn = (b1 or b2) and (b2 or not b3)

            # Fn becomes true
            if Fn:
                print("Satisfiable")
                print("{}, {}, {}".format(b1, b2, b3))

                break

        # breaks out of this loop if the prev one exits due to break
        else:
            continue
        break
    # breaks out of this loop if the prev one exits due to break
    else:
        continue
    break
# The loop isn't broken
else:
    print("Unsatifiable")
