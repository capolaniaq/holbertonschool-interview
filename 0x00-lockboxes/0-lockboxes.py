#!/usr/bin/python3
"""
This script is used to generate lockboxes
"""


def canUnlockAll(boxes):
    """
    This function checks if the boxes can be unlocked
    """
    for x, box in enumerate(boxes):
        if len(box) == 0 and x != len(boxes) - 1:
            return False
        if x == len(boxes) - 1:
            return True
