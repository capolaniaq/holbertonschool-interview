#include "sandpiles.h"

/**
 * sandpiles_sum - sums two sandpiles
 * @grid1: first sandpile
 * @grid2: second sandpile
 *
 * Return: void
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	if (grid1 == NULL || grid2 == NULL)
		return;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}

	}
}
