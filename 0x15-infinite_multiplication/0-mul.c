#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "holberton.h"

/**
 * main - multiplies two numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success
 */


int main(int argc, char const *argv[])
{
	int mul = 0;
	int num1, num2;

	if (argc != 3)
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		exit(98);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);

	mul = num1 * num2;

	if (mul % 10 == 0)
	{
		print(mul);
		_putchar('0');
	}
	else
	{
		print(mul);
	}
	_putchar('\n');

}

/**
 * print - prints the result of the multiplication
 * @mul: the result of the multiplication
 *
 * Return: void
 */

void print(int mul)
{
	int rev = 0;

	while (mul > 0)
	{
		rev = rev * 10;
		rev = rev + (mul % 10);
		mul = mul / 10;
	}

	while (rev > 0)
	{
		_putchar(rev % 10 + '0');
		rev = rev / 10;
	}

}

