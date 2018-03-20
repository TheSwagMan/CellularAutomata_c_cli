#ifndef _FILE_UTILS_H_
# define _FILE_UTILS_H_ 

# include <stdio.h>
# include <stdlib.h>

# include "grid_utils.h"

/* Grid files are composed has following :
 * SIZEOF(GRID_X)
 * GRID_X
 * SIZEOF(GRID_Y)
 * GRID_Y
 * GRID_DATA
 */

t_grid	*open_grid(char *filename);
int	save_grid(t_grid *grid, char *filename);

#endif /* _FILE_UTILS_H_ */
