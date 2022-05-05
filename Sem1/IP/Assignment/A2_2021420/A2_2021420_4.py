# CSE 101
# Assignment 2
# Problem 4
#
# By - Shivoy Arora
# Roll No - 2021420

def calMarks(student, rno):
    """ To calculate marks of the given student
        Args:
            student: name of the student
            rno: student number
        Returns:
            marks obtained by the student
    """
    global ansKey

    with open("Student/{}_{}.txt".format(student, rno), "r") as f:
        submission = [i.split() for i in f.readlines()]

    marks = 0
    for i in submission:
        if i[1] == "-":
            pass
        elif i[1] == ansKey[i[0]]:
            marks += 4
        else:
            marks -= 1

    return marks


""" Main Function """
if __name__ == "__main__":

    # importing data from RegisteredStudents.txt
    with open("Admin/RegisteredStudents.txt", "r") as f:
        regStudents = [i.split() for i in f.readlines()]

    # Getting answer key
    with open("Admin/AnswerKey.txt", "r") as f:
        ansKey = dict()

        for i in f.readlines():
            ansKey[i.split()[0]] = i.split()[1]

    # Calculating marks of each student
    for i in range(len(regStudents)):
        regStudents[i].append(
            str(calMarks(regStudents[i][0], regStudents[i][1])))

    # writing data back to RegisteredStudents.txt
    with open("Admin/FinalReport.txt", "w") as f:
        f.writelines([" ".join(i)+"\n" for i in regStudents])

    print("Final Report made Successfully!")
