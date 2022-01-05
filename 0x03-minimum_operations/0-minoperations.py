#!/usr/bin/python3
"""
Minium steps to reach a target number
"""


def minOperations(n):
    """
    Minimum Operations functions
    """
    if type(n) is not int:
        return 0
    elif n < 0:
        return 0
    if n == 1:
        return 0
    if n % 2 == 0 and n != 2:
        return minOperations(int(n / 2)) + 2
    elif n % 3 == 0 and n != 3:
        return minOperations(int(n / 3)) + 3
    else:
        return n
