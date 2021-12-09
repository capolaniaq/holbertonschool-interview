#!/usr/bin/python3
"""
This script is used to generate lockboxes
"""


def canUnlockAll(boxes):
    """
    This function checks if the boxes can be unlocked
    """
    if type(boxes) is not list:
        return False
    if len(boxes) == 0:
        return False
    for x, box in enumerate(boxes):
        if type(box) is not list:
            return False
        if len(box) == 0 and x != len(boxes) - 1:
            return False
        if x == len(boxes) - 1:
            return True
