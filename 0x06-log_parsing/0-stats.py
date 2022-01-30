#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics:
"""

import sys


if __name__ == "__main__":

    status_code = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
    file_size = 0
    total_lines = 0

    def print_values(status_code={}, file_size=0):
        """
        Prints the status code and the file size
        """
        print("File size: {}".format(file_size))
        for key, value in sorted(status_code.items()):
            if value != 0:
                print("{}: {}".format(key, value))

    try:
        for line in sys.stdin:
            if total_lines != 0 and total_lines % 10 == 0:
                print_values(status_code, file_size)
            total_lines += 1
            ln = line.split()
            try:
                status = int(ln[-2])
                file_size += int(ln[-1])
                if status in status_code:
                    status_code[status] += 1
            except ValueError:
                pass
        print_values(status_code, file_size)

    except KeyboardInterrupt:
        print_values(status_code, file_size)
        raise
