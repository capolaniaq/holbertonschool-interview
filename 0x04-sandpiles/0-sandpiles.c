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

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
	printf("=\n");
	my_print_grid(grid1);
	if (grid1[0][0] > 3 || grid1[0][1] > 3 || grid1[0][2] > 3 ||
		grid1[1][0] > 3 || grid1[1][1] > 3 || grid1[1][2] > 3 ||
		grid1[2][0] > 3 || grid1[2][1] > 3 || grid1[2][2] > 3)
	{
		stables_sandpiles(grid1);
	}
}

/**
 * stable_sandpiles - checks if a sandpile is stable
 * @grid1: first sandpile
 *
 * Return: void
 */

void stables_sandpiles(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] = grid1[i][j] - 4;
				if (i == 0 && j == 0)
				{
					grid1[i + 1][j] = grid1[i + 1][j] + 1;
					grid1[i][j + 1] = grid1[i][j + 1] + 1;
				}
				else if (i == 0 && j == 1)
				{
					grid1[i][j -1] = grid1[i][j -1] + 1;
					grid1[i][j + 1] = grid1[i][j + 1] + 1;
					grid1[i + 1][j] = grid1[i + 1][j] + 1;
				}
				else if (i == 0 && j == 2)
				{
					grid1[i + 1][j] = grid1[i + 1][j] + 1;
					grid1[i][j - 1] = grid1[i][j - 1] + 1;
				}
				else if (i == 1 && j == 0)
				{
					grid1[i - 1][j] = grid1[i - 1][j] + 1;
					grid1[i][j + 1] = grid1[i][j + 1] + 1;
					grid1[i + 1][j] = grid1[i + 1][j] + 1;
				}
				else if (i == 1 && j == 1)
				{
					grid1[i - 1][j] = grid1[i - 1][j] + 1;
					grid1[i][j - 1] = grid1[i][j - 1] + 1;
					grid1[i][j + 1] = grid1[i][j + 1] + 1;
					grid1[i + 1][j] = grid1[i + 1][j] + 1;
				}
				else if (i == 1 && j == 2)
				{
					grid1[i - 1][j] = grid1[i - 1][j] + 1;
					grid1[i][j - 1] = grid1[i][j - 1] + 1;
					grid1[i + 1][j] = grid1[i + 1][j] + 1;
				}
				else if (i == 2 && j == 0)
				{
					grid1[i - 1][j] = grid1[i - 1][j] + 1;
					grid1[i][j + 1] = grid1[i][j + 1] + 1;
				}
				else if (i == 2 && j == 1)
				{
					grid1[i - 1][j] = grid1[i - 1][j] + 1;
					grid1[i][j - 1] = grid1[i][j - 1] + 1;
					grid1[i][j + 1] = grid1[i][j + 1] + 1;
				}
				else if (i == 2 && j == 2)
				{
					grid1[i - 1][j] = grid1[i - 1][j] + 1;
					grid1[i][j - 1] = grid1[i][j - 1] + 1;
				}
			}

		}

	}

	if (grid1[0][0] > 3 || grid1[0][1] > 3 || grid1[0][2] > 3 ||
		grid1[1][0] > 3 || grid1[1][1] > 3 || grid1[1][2] > 3 ||
		grid1[2][0] > 3 || grid1[2][1] > 3 || grid1[2][2] > 3)
		{
			printf("=\n");
			my_print_grid(grid1);
			stables_sandpiles(grid1);
		}
}


void my_print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}