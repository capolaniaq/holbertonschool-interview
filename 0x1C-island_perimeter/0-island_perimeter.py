#!/usr/bin/python3
"""
Island Perimeter
"""


def island_perimeter(grid):
    """
    Function that calculate the perimeter from island

    Args:
        grid is a list of list that contain 0's and 1's
        0 represent the water
        1 represente the land

    Return:
        perimeter of the island is the grid
    """

    perimeter = 0
    for i, row in enumerate(grid):
        for j, frame in enumerate(row):
            if frame == 1:
                if i == 0 or i == len(row) - 1:
                    perimeter +=1
                if j == 0 or j == len(row) - 1:
                    perimeter +=1
                if i != len(row) - 1:
                    if grid[i + 1][j] == 0:
                        perimeter +=1
                if j != len(row) - 1:
                    if grid[i][j + 1] == 0:
                        perimeter +=1
                if j != 0:
                    if grid[i][j - 1] == 0:
                        perimeter +=1
                if i != 0:
                    if grid[i - 1][j] == 0:
                        perimeter +=1

    return perimeter
