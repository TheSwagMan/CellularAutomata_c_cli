#ifndef _GUI_H_
# define _GUI_H_ 

/* needed for usleep */
# define _DEFAULT_SOURCE
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# include "utils.h"
# include "grid_utils.h"
# include "file_utils.h"
# include "evolving.h"

typedef struct	s_com
{
	char	command;
	char	**args;
	int	nargs;
	char	*raw_cmd;
}		t_com;

void	gui(void);
t_com	*create_cmd(char *raw);
void	destroy_cmd(t_com *cmd);
t_com	*query_user(void);

#endif /* _GUI_H_ */
