#!/usr/bin/python3
"""
Rain exercise
"""


def rain(walls):
    """
    Rain function
    """
    if not walls or len(walls) == 0:
        return 0

    rain = 0
    low_wall = 0

    for i in range(1, len(walls)):
        if walls[i] == 0:
            continue
        elif walls[low_wall] <= walls[i]:
            rain = rain + (walls[low_wall]) * (i - low_wall - 1)
            low_wall = i
        else:
            rain = rain + (walls[i]) * (i - low_wall - 1)
            low_wall = i
    return rain
