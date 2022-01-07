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
    if n <= 0 or n == 1 or n is None:
        return 0
    op = 0
    div = 2
    while div <= n:
        if n % div == 0:
            op += div
            n = n // div
        else:
            div += 1
    return op
