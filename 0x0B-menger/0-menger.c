#include "menger.h"

/**
 * menger - Function that create a menger sponge
 * @level: Level of the menger sponge
 *
 * Return: void
 */

void menger(int level)
{
	int i, j;

	if (level < 0)
		return;

	for (i = 0; i < pow(3, level); i++)
	{
		for (j = 0; j < pow(3, level); j++)
		{
			if (i == 0 || i == pow(3, level) - 1 || j == 0 || j == pow(3, level) - 1)
				printf("#");
			else
				printf(" ");
		}
		printf("\n");

	}

	return;
}