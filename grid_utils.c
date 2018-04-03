#include "grid_utils.h"

/*
 * Create a new bidimentional grid of sizex and sizey by allocating memory. 
 */
t_grid	*generate_grid(int sizex, int sizey)
{
	t_grid *grid;

	if (!(grid = (t_grid *)malloc(sizeof(t_grid))))
		raise_error(ERR_MALLOC);
	grid->size_x = sizex;
	grid->size_y = sizey;
	allocate_grid(grid);
	return (grid);
}

void	allocate_grid(t_grid *grid)
{
	int i;
	if (!(grid->grid = (char **)malloc(grid->size_y * sizeof(char *))))
		raise_error(ERR_MALLOC);
	for (i = 0; i < grid->size_y; i++)
		if (!(grid->grid[i] = (char *)
					malloc(grid->size_x * sizeof(char))))
			raise_error(ERR_MALLOC);
}

/*
 * Frees a grid to release memory.
 */
void	destroy_grid(t_grid *grid)
{
	int i;
	for (i = 0; i < grid->size_y; i++)
		free(grid->grid[i]);
	free(grid->grid);
	free(grid);
}

/*
 * Display a grid according to configured chars
 */
void	display_grid(t_grid *grid)
{
	int i, j;
	for (i = 0; i < grid->size_y; i++)
	{
		for (j = 0; j < grid->size_x; j++)
		{
			/* puts the char corresponding to the cell status */
			if (grid->grid[i][j] == CELL_ALIVE)
				putchar(CELL_STR_ALIVE);
			else if (grid->grid[i][j] == CELL_DEAD)
				putchar(CELL_STR_DEAD);
			else
				raise_error(ERR_OTHER);
		}
		putchar('\n');
	}
}


/*
 * Fills a grid with the given value.
 */
void	fill_grid(t_grid *grid, int value)
{
	int i, j;
	for (i = 0; i < grid->size_y; i++)
		for (j = 0; j < grid->size_x; j++)
			/* sets the value to each cell */
			grid->grid[i][j] = value;
}


void	random_fill(t_grid *grid, int perc)
{
	int i, j;

	for (i = 0; i < grid->size_y; i++)
		for (j = 0; j < grid->size_x;j++)
			grid->grid[i][j] = rand() % 100 < perc ?
				CELL_ALIVE : CELL_DEAD;
}

t_grid	*copy_grid(t_grid *grid)
{
	t_grid *cpy;
	int i, j;

	cpy = generate_grid(grid->size_x, grid->size_y);
	for (i = 0; i < grid->size_y;i++)
		for (j = 0; j < grid->size_x; j++)
			cpy->grid[i][j] = grid->grid[i][j];
	return (cpy);
}
