#!/usr/bin/python3
"""
Count words in Reddit Api
"""
import requests


def count_words(subreddit, word_list, hot_dict={}, after=''):
    """
    request to reddit api and count the number of words
    """
    if after == '':
        word_list = [x.lower() for x in word_list]
        hot_dict = {word: 0 for word in word_list}

    url = 'https://www.reddit.com/r/{}/hot.json?after={}'.format(subreddit,
                                                                 after)
    headers = {'User-Agent': 'madmansilver'}
    response = requests.get(url, headers=headers, allow_redirects=False)
    if response.status_code != 200:
        return

    data = response.json()
    after = data['data']['after']

    for post in data['data']['children']:
        for word in word_list:
            hot_dict[word] += post['data']['title'].lower().split().count(word)

    if after is None:
        for key, value in sorted(hot_dict.items(), key=lambda x: x[1],
                                 reverse=True):
            if value != 0:
                print('{}: {}'.format(key, value))
        return

    count_words(subreddit, word_list, hot_dict, after)
