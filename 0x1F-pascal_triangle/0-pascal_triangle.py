#!/usr/bin/python3
"""Pascal Triangle"""


def pascal_triangle(n):
    """
    Function that calculate the Pascal Tringle
    Until n row

    Args:
        n is the n row for the Pascal triangle

    Return:
        The Pascal triangle
    """
    if n <= 0:
        return []

    pascal = []

    for i in range(1, n + 1):
        row = []
        for j in range(i):
            if j == 0 or j == i - 1:
                row.append(1)
            elif i != 1 and i != 2:
                prev = pascal[i - 2]
                num = prev[j - 1] + prev[j]
                row.append(num)

        pascal.append(row)

    return pascal
