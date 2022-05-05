# CSE 101
# Assignment 3
# Problem 4
#
# By - Shivoy Arora
# Roll No - 2021420

class Person:
    """ Person's details
        Args:
            fname (str): First name of the person
            lname (str): Last name of the person
            age (str): Age of the person
        Attributes:
            fname (str): First name of the person
            lname (str): Last name of the person
            age (int): Age of the person
    """

    def __init__(self, fname, lname, age):
        self.fname = fname
        self.lname = lname
        self.age = int(age)

    def __repr__(self):
        return "{} {} {}".format(self.fname, self.lname, self.age)


def firstname(x):
    """ Creating a key function for sorting by first name
        Args:
            x (Person): Person object
        Returns:
            x.fname (str): First name of the person
    """
    return x.fname.lower()


def lastname(x):
    """ Creating a key function for sorting by last name
        Args:
            x (Person): Person object
        Returns:
            x.lname (str): Last name of the person
    """
    return x.lname.lower()


def ageSort(x):
    """ Creating a key function for sorting by age
        Args:
            x (Person): Person object
        Returns:
            x.age (str): Age of the person (in string)
    """
    return str(x.age)


def sort_attribute(query):
    """ Sorting the list of people by the attribute specified by the user
        Args:
            query (str): query inputted by the user
        Returns:
            sorted_list (list[Person]): sorted list of people according to the attribute specified by the user
    """
    global people

    if query.lower() == "firstname":
        return people.sort(key=firstname)
    elif query.lower() == "lastname":
        return people.sort(key=lastname)
    elif query.lower() == "age":
        return people.sort(key=ageSort)


"""" Main Function """
if __name__ == "__main__":
    print("Welcome to the Application!\n")
    n = int(input("Enter the number of people you want to enter: "))

    people = []
    for i in range(n):
        fname = input("Enter the first name: ")
        lname = input("Enter the last name: ")
        age = input("Enter the age: ")
        people.append(Person(fname, lname, age))
        print()

    print("\n")
    q = int(input("Enter the number of queries: "))

    i = 0
    while i < q:
        query = input("Enter the query: ")

        if query.lower() in {"firstname", "lastname", "age"}:
            sort_attribute(query)

            print("\nOrder:")
            for p in people:
                print(p)

        else:
            print("Invalid query!")
            print("Try again!\n")
            continue

        i += 1
