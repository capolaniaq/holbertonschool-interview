#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics:
"""
import signal
import sys
import re

if __name__ == "__main__":

    import signal
    import sys
    import re


    def print_values(status_code={}, file_size=0):
        """
        Prints the status code and the file size
        """
        print('File size: {}'.format(file_size))
        for key, value in status_code.items():
            if value != 0:
                print('{}: {}'.format(key, value))
    try:
        k = 0
        valid = re.compile(r'^\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3} - \[.*\] "GET /projects/260 HTTP/1.1" \d{3} \d{1,5}$')
        status_code = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
        file_size = 0
        for line in sys.stdin:
            if valid.match(line):
                separator = line.split(' ')
                status_code[int(separator[-2])] += 1
                file_size = file_size + int(separator[-1])
                k += 1
                if k % 10 == 0:
                    print_values(status_code, file_size)
    except KeyboardInterrupt:
        print_values(status_code, file_size)
        sys.exit(0)


