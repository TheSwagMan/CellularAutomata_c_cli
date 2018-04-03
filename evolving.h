#ifndef _EVOLVING_H_
# define _EVOLVING_H_

# include "grid_utils.h"

# define CONWAYS	"2/23"

int	conways(char *t);
int	apply_rule(char *rule, char *t);
void	evoluate_grid(t_grid *grid, char *rule, int mode);

#endif /* _EVOLVING_H_ */
