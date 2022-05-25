#!/usr/bin/python3
"""
Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):
    """
    Given an n x n 2D matrix,
    rotate it 90 degrees clockwise.
    Doesn't Return anything, modify matrix
    in-place instead.
    """
    n = len(matrix)

    for i in range(n // 2):
        for j in range(i, n - i - 1):

            top_left = matrix[i][j]
            top_right = matrix[j][n - 1- i]
            down_right = matrix[n - 1- i][n - 1 - j]
            down_left = matrix[n - 1 - j][i]
            matrix[i][j] = down_left
            matrix[j][n - 1 - i] = top_left
            matrix[n - 1 - i][n - 1 - j] = top_right
            matrix[n - 1 - j][i] = down_right
