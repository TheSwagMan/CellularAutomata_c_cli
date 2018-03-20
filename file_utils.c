#include "file_utils.h"

t_grid	*open_grid(char *filename)
{
	FILE *file;
	t_grid *grid;
	int i, j;
	char n, t;

	/* allocating grid */
	if (!(grid = (t_grid *)malloc(sizeof(t_grid))))
		raise_error(ERR_MALLOC);
	/* opening file */
	if (!(file = fopen(filename, "rb+")))
	{
		free(grid);
		return (NULL);
	}
	/* reading size_x size */
	fread(&n, 1, 1, file);
	for (i = 0; i < n; i++)
	{
		/* shifting by one byte */
		grid->size_x <<= 8;
		/* getting value part */
		fread(&t, 1, 1, file);
		/* adding part to value */
		grid->size_x |= t;
	}
	/* reading size_y size */
	fread(&n, 1, 1, file);
	for (i = 0; i < n; i++)
	{
		/* shifting by one byte */
		grid->size_y <<= 8;
		/* getting value part */
		fread(&t, 1, 1, file);
		/* adding part to value */
		grid->size_y |= t;
	}
	/* allocate grid */
	allocate_grid(grid);
	/* fill grid */
	for (i = 0; i < grid->size_y; i++)
	{
		for (j = 0; j < grid->size_x;j++)
		{
			fread(&t, 1, 1, file);
			/* set cell state */
			grid->grid[i][j] = t == 1 ? CELL_ALIVE : CELL_DEAD;
		}
	}
	fclose(file);
	return (grid);
}

int	save_grid(t_grid *grid, char *filename)
{
	FILE *file;
	char t;
	int i, j, u;

	if (!(file = fopen(filename, "wb")))
		return (0);
	/* writing size_x */
	u = int_length(grid->size_x);
	fwrite(&u, 1, 1, file);
	for (i = 0; i < u; i++)
	{
		j = (grid->size_x >> (8 * (u - i - 1))) & 0xff;
		fwrite(&j, 1, 1, file);
	}
	/* writing size_y */
	u = int_length(grid->size_y);
	fwrite(&u, 1, 1, file);
	for (i = 0; i < u; i++)
	{
		j = (grid->size_y >> (8 * (u - i - 1))) & 0xff;
		fwrite(&j, 1, 1, file);
	}
	/* writing grid */
	for (i = 0; i < grid->size_y; i++)
	{
		for (j = 0; j < grid->size_x;j++)
		{
			t = grid->grid[i][j] == CELL_ALIVE ? 1 : 0;
			fwrite(&t, 1, 1, file);
		}
	}
	fclose(file);
	return (1);
}
