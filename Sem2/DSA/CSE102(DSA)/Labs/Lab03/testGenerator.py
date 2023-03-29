import random
import subprocess
import time


def testA(fileName="Helper/testA.txt"):
    case = ""
    n = random.randint(2, 10**5)
    m = random.randint(1, 2*10**5)
    case += f"{n} {m}\n"
    for _ in range(m):
        case += f"{random.randint(1, n)} {random.randint(1, n)}\n"

    with open(fileName, "w") as f:
        f.write(case)


def runA(exe="A"):
    # testA()
    subprocess.call(["gcc", exe+".c", "-o", "out/"+exe])
    startTime = time.time()
    subprocess.call("out/"+exe)

    print("Execution time:", time.time() - startTime)


def testB(fileName="Helper/testB.txt"):
    case = ""
    q = random.randint(1, 1000)
    case += "{}\n".format(q)

    for _ in range(q):
        n = random.randint(1, 100)
        case += "{} {}\n".format(n, random.randint(1, 10**9))

        case += " ".join([str(random.randint(1, 10**9))
                         for _ in range(n)]) + "\n"

    with open(fileName, "w") as f:
        f.write(case)


def runB(exe="B"):
    # testB()
    subprocess.call(["gcc", exe+".c", "-o", "out/"+exe])
    startTime = time.time()
    subprocess.call("out/"+exe)

    print("Execution time:", time.time() - startTime)


def testC(fileName="Helper/testC.txt"):
    case = ""
    n = random.randint(1, 10**5)
    k = random.randint(1, 10**5)
    case += "{} {}\n".format(n, k)

    case += " ".join([str(random.randint(1, 10**9))
                     for _ in range(n)]) + "\n"

    with open(fileName, "w") as f:
        f.write(case)


def runC(exe="C"):
    # testC()
    subprocess.call(["gcc", exe+".c", "-o", "out/"+exe])
    startTime = time.time()
    subprocess.call("out/"+exe)

    print("Execution time:", time.time() - startTime, "s")


if __name__ == "__main__":
    # testB()
    runB("B")
