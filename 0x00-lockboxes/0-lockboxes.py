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
    Keys = []
    for x, box in enumerate(boxes):
        if x < len(boxes) - 1:
            for key in box:
                if key not in Keys:
                    Keys.append(key)
    for i, box in enumerate(boxes):
        if i != 0 and i not in Keys:
            return False
    return True
