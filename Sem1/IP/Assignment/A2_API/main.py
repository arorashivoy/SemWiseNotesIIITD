# API Assignment Interface
# For Symbl.ai API
#
# By- Shivoy Arora

import AsyncAPI
import ConvoAPI
import GetToken
import pprint


if __name__ == "__main__":
    print("This program is the Speech To Text convertor")
    print("Developed by Shivoy Arora, Nishi Ninawat, Suhani Mathur")

    print()

    audioPath = ""

    # Menu
    while True:
        print("Press 1: To input a .mp3 file")
        print("Press 2: To use test file")

        print()

        choice = int(input("Enter your choice: "))

        if choice == 1:
            print("The input audio should be in en-US\n")
            audioPath = input(
                "Enter the path of the file audio file (in .mp3): ")
            break
        elif choice == 2:
            print("Using test audio file")
            audioPath = "test.mp3"
            break
        else:
            print("Enter a vaild choice")
            print("Try Again...\n")

    # Getting access token
    GetToken.generateAccessCode()

    # Getting conversation ID
    AsyncAPI.getAudioId(audioPath)

    # Getting the respanse
    response = ConvoAPI.getText()
    while response == {'messages': []}:
        response = ConvoAPI.getText()

    # pprint.pp(response)

    print()

    text = ""

    for i in response["messages"]:
        text += i["text"] + "\n"

    print(text)
