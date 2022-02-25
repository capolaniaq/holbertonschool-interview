#include "slide_line.h"

/**
 * slide_line - slide a line of integers
 * @line: array of integers
 * @size: size of the array
 * @direction: direction to slide the line
 *
 * Return: number of elements moved
 */

int slide_line(int *line, size_t size, int direction)
{
	size_t i = 0, j = 0;
	int number = 0;

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (-1);

	if (direction == SLIDE_LEFT)
	{
		while (i < size - 1)
		{
			if (line[i] != 0)
			{
				number = line[i];
				j = i + 1;
				while (j < size - 1)
				{
					if (line[j] == number)
					{
						number = number * 2;
						line[j] = 0;
						break;
					}
					j++;
				}
				line[i] = number;
				number = 0;
			}
			i++;
		}
		order_ceros_left(line, size);
	}
	else
	{
		slide_line_right(line, size);
		order_ceros_right(line, size);
	}

	return (1);
}

/**
 * order_ceros_left - order ceros in the array
 * @line: array of integers
 * @size: size of the array
 *
 * Return: void
 */
void order_ceros_left(int *line, size_t size)
{
	size_t i = 0, j = 0;

	while (i < size - 1)
	{
		if (line[i] == 0)
		{
			j = i + 1;
			while (j < size)
			{
				if (line[j] != 0)
				{
					line[i] = line[j];
					line[j] = 0;
					break;
				}
				j++;
			}
		}
		i++;
	}
}

/**
 * slide_line_right - slide a line of integers
 * @line: array of integers
 * @size: size of the array
 *
 * Return: number of elements moved
 */

void slide_line_right(int *line, size_t size)
{
	int number = 0;
	size_t j = 0;

	while (size > 0)
	{
		if (line[size - 1] != 0)
		{
			number = line[size - 1];
			j = size - 1;
			while (j > 0)
			{
				if (line[j - 1] == number)
				{
					number = number * 2;
					line[j - 1] = 0;
					break;
				}
				j--;
			}
			line[size - 1] = number;
			number = 0;
		}
		size--;
	}
}

/**
 * order_ceros_right - order ceros in the array
 * @line: array of integers
 * @size: size of the array
 *
 * Return: void
 */

void order_ceros_right(int *line, size_t size)
{
	size_t i = 0, j = 0;

	i = size;
	while (i > 0)
	{
		if (line[i - 1] == 0)
		{
			j = i - 1;
			while (j > 0)
			{
				if (line[j - 1] != 0)
				{
					line[i - 1] = line[j - 1];
					line[j - 1] = 0;
					break;
				}
				j--;
			}
		}
		i--;
	}
}
