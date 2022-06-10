#include "sort.h"

/**
 * merge_sort - sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 * Return: void
 */


void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	merge(array, size, 0, size - 1);
}

/**
 * merge - Function that merges two sorted arrays
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @start: Start index of the array
 * @end: End index of the array
 *
 * Return: void
 */

void merge(int *array, size_t size, size_t start, size_t end)
{
	size_t middle = 0;
	int *tmp = NULL;

	

}

