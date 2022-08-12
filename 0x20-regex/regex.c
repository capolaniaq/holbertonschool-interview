#include "regex.h"

/**
 * regex_match - checks whether a given pattern matches
 * a given string
 * @str: is the string to scan
 * @pattern: is the regular
 * Return: int 1 in success or 0 in failure case
 */

int regex_match(char const *str, char const *pattern)
{
	if (*str == '\0' && *pattern == '\0')
		return (1);

	if (*str == '\0')
		return (1);

	if (*str == *pattern)
		return (regex_match(str + 1, pattern + 1));

	if (*pattern == '.')
		return (regex_match(str + 1, pattern + 1));

	if (*pattern == '*')
	
		return (regex_match(str + 1, pattern));

	return (0);
}