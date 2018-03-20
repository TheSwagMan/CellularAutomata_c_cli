#include "utils.h"

void	raise_error(int errorn)
{
	char *err;
	err = (char *)"An error occured !";
	if (errorn == ERR_MALLOC)
		err = (char *)"Malloc failed !";
	fprintf(stderr, "%s\n", err);
	exit(errorn);
}

int	int_length(int n)
{
	int i = 1;
	while ((n >>= 8))
		i++;
	return (i);
}
