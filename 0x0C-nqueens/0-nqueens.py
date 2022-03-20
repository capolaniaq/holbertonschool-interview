#!/usr/bin/python3
"""
Module that contains the NQueens class.
"""

import sys


if len(sys.argv) != 2:
    print("Usage: nqueens N")
    exit(1)

n = int(sys.argv[1])

if type(n) is not int:
    print("N must be a number")
    exit(1)
elif n < 4:
    print("N must be at least 4")
    exit(1)


def create_chessboard(n):
    """
    Create a chessboard
    """
    chessboard = []
    for i in range(n):
        for j in range(n):
            coor = []
            coor.append(i)
            coor.append(j)
            chessboard.append(coor)
    return chessboard


def check_queens(chessboard, n, row):
    """
    try to put a queen in correct place
    """
    for i, j in chessboard:
        if i == row:
            next = chessboard.copy()
            remove_places([i, j], next)
            if row == n - 1 and len(next) == n:
                print(next)
            check_queens(next, n, row + 1)


def remove_places(queen, chessboard):
    """
    remove places that are not valid
    """
    row = queen[0]
    col = queen[1]
    chessboard_copy = chessboard.copy()
    for coord in chessboard_copy:
        if coord[0] == row and coord[1] == col:
            continue
        elif coord[0] == row or coord[1] == col:
            chessboard.remove(coord)
        elif abs(coord[0] - row) == abs(coord[1] - col):
            chessboard.remove(coord)

chessboard = create_chessboard(n)
check_queens(chessboard, n, 0)
