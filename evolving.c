#include "evolving.h"

int	conways(char *t)
{
	int s = 0, i;
	for (i = 0; i < 9; i++)
		if (t[i] == CELL_ALIVE && i != 4)
			s++;
	if (t[4] == CELL_DEAD)
	{
		if (s == 3)
			return (ACTION_BORN);
	}
	else
	{
		if (s < 2 || s > 3)
			return (ACTION_DIE);	
	}
	return (ACTION_STAY);
}

int	apply_rule(char *rule, char *t)
{
	char life[9] = {0};
	char death[9] = {0};
	int s, i, d, n;

	d = 0;
	while (*rule)
	{
		if (*rule == '/')
			d = 1;
		else
		{
			n = *rule - '0';
			if (d)
				death[n] = 1;
			else
				life[n] = 1;
		}
		rule++;
	}
	s = 0;
	for (i = 0; i < 9; i++)
		if (t[i] == CELL_ALIVE && i != 4)
			s++;
	if (t[4] == CELL_DEAD)
		return (life[s]);
	else
		return (death[s]);
}

/*
 * Evoluate a grid following a condition and a mode.
 */
void	evoluate_grid(t_grid *grid, char *rule, int mode)
{
	/* array of the cell and around cells */
	char *around;
	t_grid *cpy;
	int i, j, k;
	int mi, mj;
	int c;

	cpy = copy_grid(grid);
	if (!(around = (char *)malloc(9 * sizeof(char))))
		raise_error(ERR_MALLOC);
	for (i = 0; i < grid->size_y; i++)
	{
		for (j = 0; j < grid->size_x; j++)
		{
			for (k = 0; k < 9; k++)
			{
				/* calculation of next cells coordinates */
				mi = i + ((k / 3) - 1);
				mj = j + ((k % 3) - 1);
				if (mi < 0 || mi >= cpy->size_y
						|| mj < 0 || mi >= cpy->size_x)
				{
					if (mode == MODE_ALIVE)
						around[k] = CELL_ALIVE;
					if (mode == MODE_DEAD)
						around[k] = CELL_DEAD;
					if (mode == MODE_ROLL)
						around[k] = cpy->grid[mi % cpy->size_y]
							[mj % cpy->size_x];
				} else
					around[k] = cpy->grid[mi][mj];

			}
			c = apply_grid(rule, around);
			if (c == ACTION_BORN)
				grid->grid[i][j] = CELL_ALIVE;
			if (c == ACTION_DIE)
				grid->grid[i][j] = CELL_DEAD;
		}
	}
	destroy_grid(cpy);
}
