# 0x1F. Pascal's Triangle

## Author: Carlos Andres Polania (capolaniaq@correo.udistrital.edu.co)

-   By:  Alexa Orrico, Software Engineer at Holberton School
-   Weight:  1
-   Project will start  Aug 1, 2022 12:00 AM, must end by  Aug 5, 2022 12:00 AM
-   was  released at  Aug 3, 2022 12:00 AM
-   An auto review will be launched at the deadline

## Tasks

### 0. Pascal's Triangle


Create a function  `def pascal_triangle(n):`  that returns a list of lists of integers representing the Pascal’s triangle of  `n`:

-   Returns an empty list if  `n <= 0`
-   You can assume  `n`  will be always an integer

```
guillaume@ubuntu:~/0x1F$ cat 0-main.py
#!/usr/bin/python3
"""
0-main
"""
pascal_triangle = __import__('0-pascal_triangle').pascal_triangle

def print_triangle(triangle):
    """
    Print the triangle
    """
    for row in triangle:
        print("[{}]".format(",".join([str(x) for x in row])))


if __name__ == "__main__":
    print_triangle(pascal_triangle(5))

guillaume@ubuntu:~/0x1F$ 
guillaume@ubuntu:~/0x1F$ ./0-main.py
[1]
[1,1]
[1,2,1]
[1,3,3,1]
[1,4,6,4,1]
```