#!/usr/bin/python3
"""
Count words in Reddit Api
"""
import requests


def count_words(subreddit, word_list):
    """
    request to reddit api and count the number of words
    """
    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {'User-Agent': 'My User Agent 1.0'}
    response = requests.get(url, headers=headers, allow_redirects=False)
    if response.status_code != 200:
        print("None")
        return
    data = response.json()
    count = 0
    for post in data['data']['children']:
        for word in word_list:
            if word in post['data']['title'].lower():
                count += 1
    print(count)
