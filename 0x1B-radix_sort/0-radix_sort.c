#include "sort.h"

/**
 * radix_sort - Implement LSD radix sort algorithm
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */

void radix_sort(int *array, size_t size)
{

	if (size == 0)
		return;

	if (array == NULL)
		return;

	sort_radix_split(array, size, 0, 1);

}

/**
 * sort_radix_split - sort array with radix algorithm, and aplit numbers
 * @array: array to sort
 * @size: size of the array
 * @unist: unist to split
 * @idx: flag to finish
 *
 * Return: void
 */


void sort_radix_split(int *array, size_t size, int unist, int idx)
{
	size_t i, j;
	int tmp_1, tmp_2, tmp;


	idx = 0;
	for (i = 0; i < size; i++)
	{
		for (j = i; j > 0; j--)
		{
			if (unist == 0)
			{
				tmp_1 = array[j] % 10;
				tmp_2 = array[j - 1] % 10;
			}
			else
			{
				tmp_1 = array[j] * 10;
				tmp_2 = array[j - 1] * 10;
				if (tmp_1 > idx || tmp_2 > idx)
					idx = 1;
			}

			if (tmp_1 < tmp_2)
			{
				tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
			}

		}

	}

	print_array(array, size);

	if (idx == 0)
		sort_radix_split(array, size, unist + 1, 1);

}
