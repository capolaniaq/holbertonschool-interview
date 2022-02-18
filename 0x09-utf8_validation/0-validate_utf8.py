#!/usr/bin/python3
"""
UTF-8 Validation
"""


from traceback import print_tb


def validUTF8(data):
    """
    data is a list of integers
    Return: True if data is a valid UTF-8
    encoding, else return False
    """
    for d in data:
        if d >= 128:
            try:
                d.to_bytes(1, 'big')
            except:
                return False
    return True