# Testing Async API
# For Symbl AI API
#
# By - Shivoy Arora

import json
import requests
import GetToken


def getTextId():
    url = "https://api.symbl.ai/v1/process/text"

    payload = {
        "name": "Song Lyrics",  # <Optional,String| your_meeting_name by default conversationId>

        "confidenceThreshold": 0.6,
        # <Optional,double| Minimum required confidence for the insight to be recognized. Value ranges between 0.0 to 1.0. Default value is 0.5.>

        "detectPhrases": True,
        # <Optional,boolean| It shows Actionable Phrases in each sentence of conversation. These sentences can be found using the Conversation's Messages API. Default value is false.>

        "messages": [
            {
                # "duration": {"startTime": "2020-07-21T16:04:19.99Z", "endTime": "2020-07-21T16:04:20.99Z"},
                # <Optional, object| Duration object containing startTime and/or endTime for the transcript.>, e.g.
                "payload": {
                    "content": """  It's been a while since we've been alone
                                    To turn off the world and the telephone
                                    I need to tell you you're beautiful
                                    'Cause it's been a while and I apologize
                                    I just get caught up in the rat race I'm runnin'
                                    Chasin' a moment, I'm hoping is comin'
                                    If I stopped and took a look around
                                    It's in front of my eyes, eyes """,
                    "contentType": "text/plain"
                },
                "from": {}
                # <Optional, object| Information about the User information i.e. name and/or userId, produced the content of this message.>
            }
        ]
    }

    # set your access token here.
    with open("Keys.json", "r") as f:
        keys = json.load(f)
    access_token = keys["accessToken"]

    headers = {
        'Authorization': 'Bearer ' + access_token,
        'Content-Type': 'application/json'
    }

    # webhookUrl = <Optional, string| your_webhook_url| Webhook url on which job updates to be sent. (This should be post API)>" e.g https://yourdomain.com/jobs/callback
    # if webhookUrl is not None:
    #   url += "?webhookUrl" + webhookUrl

    responses = {
        400: 'Bad Request! Please refer docs for correct input fields.',
        401: 'Unauthorized. Please generate a new access token.',
        404: 'The conversation and/or it\'s metadata you asked could not be found, please check the input provided',
        429: 'Maximum number of concurrent jobs reached. Please wait for some requests to complete.',
        500: 'Something went wrong! Please contact support@symbl.ai'
    }

    response = requests.request(
        "POST", url, headers=headers, data=json.dumps(payload))

    # Checking the response
    if response.status_code == 201:
        # Successful API execution

        # ID to be used with Conversation API.
        print("conversationId => " + response.json()['conversationId'])
        # ID to be used with Job API.
        print("jobId => " + response.json()['jobId'] + "\n\n")

        # Writing to Keys.json
        keys["conversationId"] = response.json()['conversationId']
        keys["jobId"] = response.json()['jobId']

        with open("Keys.json", "w") as f:
            json.dump(keys, f, indent=4)

        print("Successfully Updated Keys.json")

    # Generating new Access Code
    elif response.status_code == 401:
        print("Unauthorised, new Access Code needed...\n")
        print("New Access Code generated")
        GetToken.generateAccessCode()
        getTextId()

    elif response.status_code in responses.keys():
        print(responses[response.status_code])  # Expected error occurred
    else:
        print("Unexpected error occurred. Please contact support@symbl.ai" +
              ", Debug Message => " + str(response.text))


def getAudioId(audioPath: str):
    url = "https://api.symbl.ai/v1/process/audio"

    payload = None
    numberOfBytes = 0

    try:
        # Audio File path
        audio_file = open(audioPath, 'rb')
        payload = audio_file.read()
        numberOfBytes = len(payload)
    except FileNotFoundError:
        print("Could not read the file provided.")
        exit()

    # set your access token here.
    with open("Keys.json", "r") as f:
        keys = json.load(f)
    access_token = keys["accessToken"]

    headers = {
        'Authorization': 'Bearer ' + access_token,
        # This should correctly indicate the length of the request body in bytes.
        'Content-Length': str(numberOfBytes),
        'Content-Type': 'audio/mp3'
        # This is OPTIONAL field which describes the format and codec of the provided audio data. Accepted values are audio/wav, audio/mpeg, audio/mp3 and audio/wave only. If your audio is in formats other than don't use this field.
    }

    params = {
        'name': "AudioRecording",
        # <Optional, string| your_conversation_name | Your meeting name. Default name set to conversationId.>

        # 'webhookUrl': "https://yourdomain.com/jobs/callback",
        # <Optional, string| your_webhook_url| Webhook url on which job updates to be sent. (This should be post API)>

        # 'customVocabulary': ['Platform', 'Discussion', 'Targets'],
        # <Optional, list| custom_vocabulary_list> |Contains a list of words and phrases that provide hints to the speech recognition task.

        'confidenceThreshold': 0.6,
        # <Optional, double| confidence_threshold | Minimum required confidence for the insight to be recognized.>

        # 'detectPhrases': True,
        # <Optional, boolean| detect_phrases> |Accepted values are true & false. It shows Actionable Phrases in each sentence of conversation. These sentences can be found in the Conversation's Messages API.

        # 'enableSeparateRecognitionPerChannel': True,
        # "<Optional, boolean| enable_separate_recognition_per_channel> |Enables Speaker Separated Channel audio processing. Accepts true or false.

        # 'channelMetadata': [{"channel": 1, "speaker": {"name": "Robert Bartheon", "email": "robertbartheon@example.com"}}],
        # ["<Optional, boolean| channel_metadata> |This object parameter contains two variables speaker and channel to specific which speaker corresponds to which channel. This object only works when enableSeparateRecognitionPerChannel query param is set to true."

        'languageCode': "en-US"
        # <Optional, boolean| language_code> |code of language of recording.
    }

    responses = {
        400: 'Bad Request! Please refer docs for correct input fields.',
        401: 'Unauthorized. Please generate a new access token.',
        404: 'The conversation and/or it\'s metadata you asked could not be found, please check the input provided',
        429: 'Maximum number of concurrent jobs reached. Please wait for some requests to complete.',
        500: 'Something went wrong! Please contact support@symbl.ai'
    }

    response = requests.request(
        "POST", url, headers=headers, data=payload, params=json.dumps(params))

    # Checking the response
    if response.status_code == 201:
        # Successful API execution

        # ID to be used with Conversation API.
        # print("conversationId => " + response.json()['conversationId'])
        # ID to be used with Job API.
        # print("jobId => " + response.json()['jobId'] + "\n\n")

        # Writing to Keys.json
        keys["conversationId"] = response.json()['conversationId']
        keys["jobId"] = response.json()['jobId']

        with open("Keys.json", "w") as f:
            json.dump(keys, f, indent=4)

        return True
        # print("Successfully Updated Keys.json")

    # Generating new Access Code
    elif response.status_code == 401:
        # print("Unauthorised, new Access Code needed...\n")
        # print("New Access Code generated")
        GetToken.generateAccessCode()
        getAudioId()

    elif response.status_code in responses.keys():
        print(responses[response.status_code])  # Expected error occurred
    else:
        print("Unexpected error occurred. Please contact support@symbl.ai" +
              ", Debug Message => " + str(response.text))


if __name__ == "__main__":
    getAudioId("test.mp3")
