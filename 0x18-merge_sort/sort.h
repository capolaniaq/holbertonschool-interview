#ifndef _SORT_H_
#define _SORT_H_


#include <stdlib.h>
#include <stdio.h>



void print_array(int *array, int size);
void merge_sort(int *array, size_t size);
void merge(int *array, size_t size, size_t start, size_t end);




#endif // _SORT_H_

