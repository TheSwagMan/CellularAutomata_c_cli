#ifndef _GRID_UTILS_H_
# define _GRID_UTILS_H_ 1

# include <stdlib.h>
# include <stdio.h>

# include "utils.h"

# define CELL_DEAD	0
# define CELL_ALIVE	1

# define CELL_STR_DEAD	'.'
# define CELL_STR_ALIVE 'O'

# define MODE_DEAD	0
# define MODE_ALIVE	1
# define MODE_ROLL	2

# define ACTION_DIE	0
# define ACTION_BORN	1
# define ACTION_STAY	2

typedef struct	s_grid {
	char **grid;
	int size_x;
	int size_y;
}		t_grid;

t_grid	*generate_grid(int sizex, int sizey);
void	allocate_grid(t_grid *grid);
void	destroy_grid(t_grid *grid);
void	display_grid(t_grid *grid);
void	fill_grid(t_grid *grid, int value);
void	evoluate_grid(t_grid *grid, int (*condition)(char *), int mode);
void	random_fill(t_grid *grid, int perc);
t_grid	*copy_grid(t_grid *grid);

#endif /* ifndef _GRID_UTILS_H_ */
