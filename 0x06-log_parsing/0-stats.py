#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics:
"""

import sys
import re


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
            print('File size: {}'.format(file_size))
            for key, value in status_code.items():
                print('{}: {}'.format(key, value))
            status_code = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0,
                           404: 0, 405: 0, 500: 0}
            file_size = 0
    else:
        pass
