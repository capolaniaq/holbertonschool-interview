#!/usr/bin/python3
"""
UTF-8 Validation
"""


def validUTF8(data):
    """
    Return: True if data is a valid UTF-8
    encoding, else return False
    """
    for d in data:
        if d == 127 or d > 255:
            return False
    return True
