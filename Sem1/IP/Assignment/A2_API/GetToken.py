# Get Authentication Token
# For Symbl AI API
#
# By - Shivoy Arora

import requests
import json


def generateAccessCode():
    """ Generates Symbol Access code """

    url = "https://api.symbl.ai/oauth2/token:generate"

    # Authentication Keys
    with open("Keys.json", "r") as f:
        keys = json.load(f)

    appId = keys["appId"]
    appSecret = keys["appSecret"]

    payload = {
        "type": "application",
        "appId": appId,
        "appSecret": appSecret
    }
    headers = {
        'Content-Type': 'application/json'
    }

    responses = {
        400: 'Bad Request! Please refer docs for correct input fields.',
        401: 'Unauthorized. Please generate a new access token.',
        404: 'The conversation and/or it\'s metadata you asked could not be found, please check the input provided',
        429: 'Maximum number of concurrent jobs reached. Please wait for some requests to complete.',
        500: 'Something went wrong! Please contact support@symbl.ai'
    }

    response = requests.request(
        "POST", url, headers=headers, data=json.dumps(payload))

    # Successful API execution
    if response.status_code == 200:
        # Writing token to the json
        keys["accessToken"] = response.json()["accessToken"]

        with open("Keys.json", "w") as f:
            json.dump(keys, f, indent=4)

        # print("Successfully Updated Keys.json")

    # Expected error occurred
    elif response.status_code in responses.keys():
        print(responses[response.status_code], response.text)
    else:
        print("Unexpected error occurred. Please contact support@symbl.ai" +
              ", Debug Message => " + str(response.text))


if __name__ == "__main__":
    generateAccessCode()
