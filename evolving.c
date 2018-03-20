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
