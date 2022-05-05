# CSE 101
# Assignment 3
# Problem 3
#
# By - Shivoy Arora
# Roll No - 2021420
from datetime import datetime


class BankAccount:
    """ Bank Account details of a person 
        Args:
            uname (str): Username of the person
            password (str): Password of the person
            currentBalance (int): Current balance of the person
    """

    def __init__(self, uname, password, currentBalance):
        self.uname = uname
        self.password = password
        self.currentBalance = currentBalance

        file = open("{}.txt".format(self.uname), "w")
        file.close()

    def authenticate(self):
        """Authenticating the user"""
        password = input("Enter your password: ")

        if password == self.password:
            return True
        else:
            return False

    def deposit(self, amount):
        """Depositing the amount"""
        try:
            i = 0
            while True:
                if self.authenticate():
                    break
                else:
                    i += 1
                    assert i > 3, "Too many wrong attempts!!"

        except AssertionError as a:
            print(a)

            return

        self.currentBalance += amount

        file = open("{}.txt".format(self.uname), "a")
        file.write("{} The amount of Rs. {} has been added \tCurrent Balance: Rs. {}\n".format(
            datetime.now(), amount, self.currentBalance))

        file.close()

    def withdraw(self, amount):
        """Withdrawing the amount"""
        try:
            i = 0
            while True:
                if self.authenticate():
                    break
                else:
                    i += 1
                    assert i > 3, "Too many wrong attempts!!"

        except AssertionError as a:
            print(a)
            return

        if self.currentBalance < amount:
            print("Low balance!! Cannot be debited at this time!")
            return

        self.currentBalance -= amount

        file = open("{}.txt".format(self.uname), "a")
        file.write("{} The amount of Rs. {} has been debited \tCurrent Balance: Rs. {}\n".format(
            datetime.now(), amount, self.currentBalance))

        file.close()

    def bankStatement(self):
        """Printing the bank statement"""
        try:
            i = 0
            while True:
                if self.authenticate():
                    break
                else:
                    i += 1
                    assert i > 3, "Too many wrong attempts!!"

        except AssertionError as a:
            print(a)
            return

        file = open("{}.txt".format(self.uname), "r")
        print(file.read())
        file.close()


""" Main Function """
if __name__ == "__main__":
    print("Welcome to the bank of IIITD")

    # Getting Name
    while True:
        name = input("Enter your name: ")
        if name == "":
            print("Enter a valid name")
            print("Try Again...\n")
        else:
            break

    # Getting Password
    while True:
        password = input("Enter your password: ")
        if len(password) < 3:
            print("Password must be at least 3 characters long")
            print("Try Again...\n")
        elif password.isdigit():
            print("Password must contain at least one letter")
            print("Try Again...\n")
        elif password.isalpha():
            print("Password must contain at least one number")
            print("Try Again...\n")
        else:
            break

    # Getting Balance
    while True:
        currentBalance = int(input("Enter your current balance: "))

        if currentBalance < 0:
            print("Balance cannot be negative")
            print("Try Again...\n")
        else:
            break

    # Creating the account
    account = BankAccount(name, password, currentBalance)

    # Menu
    while True:

        print("\n")
        print("*" * 80)

        print("Press 1: To deposit")
        print("Press 2: To withdraw")
        print("Press 3: To check your bank statement")
        print("Press 4: To exit")

        choice = int(input("Enter your choice: "))

        print()

        if choice == 1:
            amount = int(input("Enter the amount to be deposited: "))
            account.deposit(amount)
        elif choice == 2:
            amount = int(input("Enter the amount to be withdrawn: "))
            account.withdraw(amount)
        elif choice == 3:
            account.bankStatement()
        elif choice == 4:
            print("Thank you for using our bank")
            break
        else:
            print("Enter a valid choice")
            print("Try Again...\n")
