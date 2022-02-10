#include "palindrome.h"

/**
 * is_palindrome - check if a number is a palindrome
 * @n: number to check
 *
 * Return: 1 if it is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long rev = 0, tmp = n;

	while (n)
	{
		rev = rev * 10 + n % 10;
		n /= 10;
	}

	if (rev == tmp)
		return (1);
	return (0);


}


