#!/usr/bin/python3
"""
Minium steps to reach a target number
"""

def minOperations(n):
    """
    Minimum Operations functions
    """
    if not isinstance(n, int):
        return 0

    op = 0
    i = 2
    while (i <= n):
        if not (n % i):
            n = int(n / i)
            op += i
            i = 1
        i += 1
    return op
