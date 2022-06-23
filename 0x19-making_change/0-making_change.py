#!/usr/bin/python3
"""
make change
"""


def makeChange(coins, total):
    """
    Args:
        coins is a list of the values of the coins in your possesion
        total the value to complete
    Returns:
         fewest number of coins needed to meet total
    """
    if total <= 0:
        return 0

    coins.sort(reverse=True)
    number = 0
    count_number = 0
    i = 0
    while i < len(coins):
        if number + coins[i] <= total:
            number += coins[i]
            count_number += 1
        else:
            i += 1

    if number != total:
        return -1

    return count_number
