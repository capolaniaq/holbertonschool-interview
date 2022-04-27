#include "search_algos.h"

/**
 * print_array - Function that print the array
 * @array: pointer to inicial parameter
 * @low: size_t type is firts parameter
 * @size: size_t type is de size of the array
 *
 * Return: void
 */

void print_array(int *array, size_t low, size_t size)
{
	size_t idx;

	if (low == size)
		return;
	printf("Searching in array: ");
	for (idx = low; idx < size; idx++)
	{
		printf("%d", array[idx]);
		if (idx != size - 1)
			printf(", ");
		else
			printf("\n");
	}
}

/**
 * binarySearch - Function that find the argument
 * @arr: pointer the array
 * @l: type size_t firts parameter
 * @r: type size_t size
 * @x: integer for the search
 *
 * Return: integer indicated the index
 */

int binarySearch(int *arr, size_t l, size_t r, int x)
{
	int mid;

	print_array(arr, l, r  + 1);
	if (r >= l)
	{
		mid = l + (r - l) / 2;
		if (arr[mid] == x && arr[mid - 1] != x)
			return (mid);
		if (arr[mid] == x && arr[mid - 1] == x)
			return (binarySearch(arr, l, mid - 1, x));
		if (arr[mid] > x)
			return (binarySearch(arr, l, mid - 1, x));
		return (binarySearch(arr, mid + 1, r, x));
	}
	return (-1);
}

/**
 * binary_search - Function that find parameter
 * @array: array to search
 * @size: size of the array
 * @value: integer indicated the value to search
 *
 * Return: integer and is the index
 */

int advanced_binary(int *array, size_t size, int value)
{
	int idx = 0;

	if (array == NULL || size < 1 || value < 0)
		return (-1);

	idx = binarySearch(array, 0, size - 1, value);
	return (idx);
}