# Testing Conversation API
# For Symbl AI API
#
# By - Shivoy Arora

import requests
import json
import pprint


def getText():
    with open("Keys.json", "r") as f:
        keys = json.load(f)

    baseUrl = "https://api.symbl.ai/v1/conversations/{conversationId}/messages"

    # Generated using Submit text end point
    conversationId = keys["conversationId"]

    url = baseUrl.format(conversationId=conversationId)

    # set your access token here.
    access_token = keys["accessToken"]

    headers = {
        'Authorization': 'Bearer ' + access_token,
        'Content-Type': 'application/json'
    }

    responses = {
        401: 'Unauthorized. Please generate a new access token.',
        404: 'The conversation and/or it\'s metadata you asked could not be found, please check the input provided',
        500: 'Something went wrong! Please contact support@symbl.ai'
    }

    response = requests.request("GET", url, headers=headers)

    if response.status_code == 200:
        # Successful API execution

        return response.json()

    elif response.status_code in responses.keys():
        print(responses[response.status_code])  # Expected error occurred
    else:
        print("Unexpected error occurred. Please contact support@symbl.ai" +
              ", Debug Message => " + str(response.text))


if __name__ == "__main__":
    response = getText()
    pprint.pp(response)
