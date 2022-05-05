# CSE 101
# Assignment 2
# Problem 5
#
# By - Shivoy Arora
# Roll No - 2021420

def noteCreate():
    """ To write Major and Minor scale in scalemajor.txt and scaleminor.txt resp."""
    global notes

    # writing major scale
    with open("scalemajor.txt", "w") as f:
        for i in range(len(notes)):
            scale = [notes[i], notes[(i+2) % 12], notes[(i+4) % 12], notes[(i+5) % 12], notes[(
                i+7) % 12], notes[(i+9) % 12], notes[(i+11) % 12], notes[(i+12) % 12]]

            f.write(" ".join(scale+["\n"]))

    # Writing minor scale
    with open("scaleminor.txt", "w") as f:
        for i in range(len(notes)):
            scale = [notes[i], notes[(i+2) % 12], notes[(i+3) % 12], notes[(i+5) % 12], notes[(
                i+7) % 12], notes[(i+8) % 12], notes[(i+10) % 12], notes[(i+12) % 12]]

            f.write(" ".join(scale+["\n"]))


def majorNotes(root):
    """ To fetch the major scale of the root from scalemajor.txt
        Args: 
            root: root whose scale is to be fetched

        Return: Major scale of the root
    """
    with open("scalemajor.txt", "r") as f:
        while True:
            scale = f.readline().split()

            if root.upper() == scale[0]:
                return scale


def minorNotes(root):
    """ To fetch the minor scale of the root from scaleminor.txt
        Args: 
            root: root whose scale is to be fetched

        Return: Minor scale of the root
    """
    with open("scaleminor.txt", "r") as f:
        while True:
            scale = f.readline().split()

            if root.upper() == scale[0]:
                return scale


if __name__ == "__main__":
    notes = ("C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B")

    # creating the scale files
    noteCreate()

    # inputting the root
    while True:
        root = input("Enter the root: ")

        if root.upper().strip() in notes:
            break
        else:
            print("Enter a valid root")
            print("Roots can be \"", " ".join(notes))
            print("Try Again...\n")

    # inputting scale
    while True:
        scale = input("Enter the type of scale (Major/Minor): ")

        # Major scale
        if scale.upper().strip() == "MAJOR":
            print("The Major scale in the key of {} is:".format(root.upper()))
            print(" ".join(majorNotes(root)))
            break

        # Minor scale
        elif scale.upper().strip() == "MINOR":
            print("The Minor scale in the key of {} is:".format(root.upper()))
            print(" ".join(minorNotes(root)))
            break

        else:
            print("Enter a valid scale")
            print("Try Again...\n")
