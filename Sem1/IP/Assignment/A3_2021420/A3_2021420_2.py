# CSE 101
# Assignment 3
# Problem 2
#
# By - Shivoy Arora
# Roll No - 2021420

class LaundryService:
    """ Details of laundry given by a customer
        Args:
            name (str): Name of the person
            contact (str): Contact of the person
            email (str): Email of the person
            typeCloth (str): Type of cloth
            branded (bool): Whether the cloth is branded or not
            season (str): Season of the cloth

        Attributes:
            name (str): Name of the person
            contact (str): Contact of the person
            email (str): Email of the person
            typeCloth (str): Type of cloth
            branded (bool): Whether the cloth is branded or not
            season (str): Season of the cloth
            id (int): ID of the customer
    """

    def __init__(self, name, contact, email, typeCloth, branded, season):
        global id

        id += 1

        self.name = name
        self.contact = contact
        self.email = email
        self.typeCloth = typeCloth
        self.branded = branded
        self.season = season
        self.id = id

    def customerDetails(self):
        """Printing the customer's details"""
        print("ID:", self.id)
        print("Name: ", self.name)
        print("Contact: ", self.contact)
        print("Email: ", self.email)
        print("Type of Cloth: ", self.typeCloth)
        print("Branded: ", self.branded)

    def calculateCharge(self):
        """Calculating the charge"""
        if self.typeCloth.lower() == "cotton":
            charge = 50
        elif self.typeCloth.lower() == "silk":
            charge = 30
        elif self.typeCloth.lower() == "woolen":
            charge = 90
        elif self.typeCloth.lower() == "polyester":
            charge = 20

        if self.branded:
            charge *= 1.5

        if self.season.lower() == "winter":
            charge *= 0.5
        elif self.season.lower() == "summer":
            charge *= 2

        return charge

    def finalDetails(self):
        """Printing the final details"""
        print("Customer's Details: ")

        self.customerDetails()

        total = self.calculateCharge()
        print("Total Charge:", total)

        if total > 200:
            print("To be returned in 4 days")
        else:
            print("To be returned in 7 days")


""" Main Function """
if __name__ == "__main__":
    id = 0

    while True:
        # Getting details of customer as well as checking them
        # Name
        while True:
            name = input("Enter Customer's Name: ")
            if name == "":
                print("Enter a valid name")
                print()
            else:
                break

        # Contact
        while True:
            contact = input("Enter Customer's Contact: ")
            if len(contact) != 10 or contact.isdigit() == False:
                print("Enter a valid contact")
                print()
            else:
                break

        # Email
        while True:
            email = input("Enter Customer's Email: ")
            if "@" not in email or "." not in email:
                print("Enter a valid email address")
                print()
            elif email.split("@")[1].find(".") == -1:
                print("Enter a valid email address")
                print()
            else:
                break

        # Type of Cloth
        while True:
            typeCloth = input(
                "Enter type of cloth (Cotton, Silk, Woolen, Polyester): ")
            if typeCloth.lower() not in ["cotton", "silk", "woolen", "polyester"]:
                print("Enter a valid type of cloth")
                print()
            else:
                break

        # Branded
        branded = input("Is it branded? (Y/n): ")
        if branded.lower() == "y":
            branded = True
        else:
            branded = False

        # Season
        while True:
            season = input("Enter season (Winter, Summer): ")
            if season.lower() not in ["winter", "summer"]:
                print("Enter a valid season")
                print()
            else:
                break

        print("\n")
        print("*"*80)

        # Creating object of class LaundryService
        customer = LaundryService(
            name, contact, email, typeCloth, branded, season)
        customer.finalDetails()

        print("*"*80)
        print()
        # Asking if user wants to continue
        choice = input("Do you want to continue? (Y/n): ")
        if choice.lower() != "y":
            break

        print("\n\n")
