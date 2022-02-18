#!/usr/bin/python3
"""
UTF-8 Validation
"""


from cgi import print_directory
import re


def validUTF8(data):
    """
    data is a list of integers
    Return: True if data is a valid UTF-8
    encoding, else return False
    """
    byte_count = 0
 
    for i in data:
        if byte_count == 0:
            if i >> 5 == 0b110 or i >> 5 == 0b1110:
                byte_count = 1
            elif i >> 4 == 0b1110 or i >> 4 == 0b1111:
                byte_count = 2
            elif i >> 3 == 0b11110 or i >> 3 == 0b11111:
                byte_count = 3
            elif i >> 7 == 0b1:
                return False
        else:
            if i >> 6 != 0b10:
                return False
            byte_count -= 1
        if byte_count == 0:
            return True
    return byte_count == 0
