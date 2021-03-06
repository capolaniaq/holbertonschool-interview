#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H
#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1



#include <stdio.h>
#include <stdlib.h>

int slide_line(int *line, size_t size, int direction);
void order_ceros_left(int *line, size_t size);
void order_ceros_right(int *line, size_t size);
void slide_line_right(int *line, size_t size);



#endif /* SLIDE_LINE_H */