#ifndef _UTILS_H_
# define _UTILS_H_	1

# include "stdio.h"
# include "stdlib.h"

# define NO_ERR		EXIT_SUCCESS
# define ERR_MALLOC	1
# define ERR_OTHER	-1 

void	raise_error(int errorn);
int	int_length(int n);

#endif /* ifndef _UTILS_H_ */
