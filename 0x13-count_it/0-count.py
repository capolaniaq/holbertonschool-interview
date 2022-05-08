#!/usr/bin/python3
"""
Count words in Reddit Api
"""
import requests


def count_words(subreddit, word_list, hot_dict={}, after=None, count=0):
    """
    request to reddit api and count the number of words
    """
    if after is None:
        [hot_dict.update({x.lower(): 0}) for x in word_list]
    url = 'https://www.reddit.com/r/{}/hot.json?after={}'.format(subreddit,
                                                                 after)
    headers = {'User-Agent': 'My User Agent 1.0'}
    response = requests.get(url, headers=headers, allow_redirects=False)
    if response.status_code != 200:
        return

    data = response.json()
    after = data['data']['after']

    for word in word_list:
        if word in data['data']['children'][count]['data']['title'].lower():
            hot_dict[word] += 1
    count += 1

    if count < len(data['data']['children']):
        count_words(subreddit, word_list, hot_dict, after, count)
    else:
        for key, value in hot_dict.items():
            print('{}: {}'.format(key, value))
