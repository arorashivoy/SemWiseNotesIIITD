# CSE 101
# Assignment 3
# Problem 5
#
# By - Shivoy Arora
# Roll No - 2021420

class Student:
    """ Details of a student

        Args:
            name (str): Name of the student
            cgpa (float): CGPA of the student
            branch (str): Branch of the student
        Attributes:
            name (str): Name of the student
            cgpa (float): CGPA of the student
            branch (str): Branch of the student
            isPlaced (bool): Whether the student is placed or not
    """

    def __init__(self, name: str, cgpa: float, branch: str):
        self.name = name
        self.cgpa = cgpa
        self.branch = branch.upper()
        self.isPlaced = False

    def isEligible(self, company: 'Company'):
        if self.cgpa >= company.cgpa_cutoff and self.branch in company.branches and not self.isPlaced:
            print("Student {} is eligible for {}".format(self.name, company.name))
            return True

        else:
            print("Student {} is not eligible for {}".format(
                self.name, company.name))
            return True

    def apply(self, company: 'Company'):
        company.appliedStudents.append(self)

    def getsPlaced(self):
        self.isPlaced = True


class Company:
    """ Hiring Company

        Args:
            name (str): Name of the company
            cgpa_cutoff (float): CGPA cutoff for the company
            branches (list[str]): List of branches the company is looking for
            positionOpen (int): Number of open positions

        Attributes:
            name (str): Name of the company
            cgpa_cutoff (float): CGPA cutoff for the company
            branches (list[str]): List of branches the company is looking for
            positionOpen (int): Number of open positions
            appliedStudents (list[Student]): List of students applied for the company
            applicationOpen (bool): True if application is open, False otherwise
            hiredStudents (list[Student]): List of students hired by the company
     """

    def __init__(self, name, cgpa_cutoff, branches, positionOpen):
        self.name = name
        self.cgpa_cutoff = cgpa_cutoff
        self.branches = branches
        self.positionOpen = positionOpen
        self.appliedStudents = []
        self.applicationOpen = True
        self.hiredStudents = []

    def hireStudent(self):
        self.appliedStudents.sort(key=cgpaSort, reverse=True)

        self.hiredStudents = self.appliedStudents[:self.positionOpen]

        print("List of students hired by {}:".format(self.name))
        for student in self.hiredStudents:
            student.getsPlaced()
            print("\t", student.name)

        print("\nSeats left:", self.positionOpen - len(self.hiredStudents))

    def closeApplication(self):
        self.applicationOpen = False
        print("Number of students hired by {}: {}".format(
            self.name, len(self.hiredStudents)))


def cgpaSort(student: Student):
    """ To be the key to sort the students according to their cgpa

        Args:
            student: Student object
        Returns:
            cgpa (int): cgpa of the entered student
    """
    return student.cgpa


""" Main Function """
if __name__ == "__main__":

    # Students
    n = int(input("Enter number of students: "))
    print()

    students = []
    for i in range(n):
        # Name
        name = input("Enter name of student {}: ".format(i + 1))
        # CGPA
        while True:
            cgpa = float(input("Enter CGPA of student {}: ".format(i + 1)))
            if cgpa >= 0 and cgpa <= 10:
                break
            else:
                print("CGPA should be between 0 and 10")
                print("Try Again...\n")

        # Branch
        while True:
            branch = input("Enter branch of student {}: ".format(i + 1))
            if branch.upper() in {"CSE", "CSAM", "ECE"}:
                break
            else:
                print("Branch should be CSE, CSAM or ECE")
                print("Try Again...\n")

        students.append(Student(name, cgpa, branch))
        print()

    # Companies
    print()
    n = int(input("Enter number of companies: "))
    print()

    companies = []
    for i in range(n):
        # Name
        name = input("Enter name of company {}: ".format(i + 1))

        # CGPA
        while True:
            cgpa_cutoff = float(
                input("Enter CGPA cutoff of company {}: ".format(i + 1)))
            if cgpa_cutoff >= 0 and cgpa_cutoff <= 10:
                break
            else:
                print("CGPA cutoff should be between 0 and 10")
                print("Try Again...\n")

        # Branches
        while True:
            branches = [i.upper() for i in input(
                "Enter space-seaprated branches of company {}: ".format(i + 1)).split()]
            for branch in branches:
                if branch.upper() in {"CSE", "CSAM", "ECE"}:
                    continue
                else:
                    print("Branch should be CSE, CSAM or ECE")
                    print("Try Again...\n")
                    break
            else:
                break

        # Number of Position Open
        while True:
            positionOpen = int(
                input("Enter number of open positions of company {}: ".format(i + 1)))
            if positionOpen > 0:
                break
            else:
                print("Number of open positions should be greater than 0")
                print("Try Again...\n")

        company = Company(name, cgpa_cutoff, branches, positionOpen)

        # Checking if students are eligible
        print("\nEligible students are: ")
        for i in students:
            if i.isEligible(company) and i.isPlaced == False:
                i.apply(company)

        print()

        # Hiring Students
        company.hireStudent()

        print()

        company.closeApplication()
        print("\n")
