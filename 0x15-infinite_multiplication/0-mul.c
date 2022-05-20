#include "holberton.h"
#include <stdlib.h>

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
	char num1, num2;

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

	num1 = argv[1];
	num2 = argv[2];

	mul = num1 * num2;

	if (mul % 10 == 0)
	{
		_printf_to_mul(mul);
		_putchar('0');
	}
	else
	{
		_printf_to_mul(mul);
	}
	_putchar('\n');

}

/**
 * print - prints the result of the multiplication
 * @mul: the result of the multiplication
 *
 * Return: void
 */

void _printf_to_mul(int mul)
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

