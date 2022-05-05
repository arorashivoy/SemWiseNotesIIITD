# /A2_2021420_B1/cases.py
#
# By - Shivoy Arora
# Roll No - 2021420

def function1(nums):
    """ To find the unit digit of product of some integers
        Args:
            nums: list of integers
        Returns:
            unit digit of the product of the given integers
    """
    product = 1
    for i in nums:
        product *= i

    return product % 10


def generateData():
    """ Creates input-output pairs """

    print("This function calculates the unit digit of products of integers")
    n = int(input("Enter number of inputs: "))

    for i in range(n):
        intList = input("Enter space-separated integers {}: ".format(i+1))

        with open("input{}.txt".format(i), "w") as f:
            f.write(intList)

        with open("index.txt", "a") as f:
            f.write("{}\n".format(i))

        intList = [int(j) for j in intList.split()]

        out = function1(intList)

        with open("output{}.txt".format(i), "w") as f:
            f.write(str(out))


if __name__ == "__main__":
    generateData()
