#ifndef _GAME_OF_LIFE_H_
# define _GAME_OF_LIFE_H_ 1

# include <getopt.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "utils.h"
# include "grid_utils.h"
# include "file_utils.h"
# include "gui.h"

# define DEFAULT_GRID_SIZE	20

t_grid	*open_grid(char *filename);

#endif /* ifndef _GAME_OF_LIFE_H_ */
