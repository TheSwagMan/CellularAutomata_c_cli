#include "gui.h"

void	gui(void)
{
	t_com *c;
	t_grid *grid = NULL;
	int i, n, t;
	char *rule;

	rule = (char *)CONWAYS;
	while (1)
	{
		c = query_user();
		switch (c->command) {
			case 'f':
				if (c->nargs >= 1)
				{
					if (grid)
					{
						destroy_grid(grid);
						grid = NULL;
					}
					grid = open_grid(c->args[0]);
					if (!grid)
						printf("Couldn't open the file !\n");
				}
				else
					printf("%c command needs an argument !\n", c->command);
				break;
			case 'd':
				if (grid)
					display_grid(grid);
				else
					printf("The grid must be initialized !\n");
				break;
			case 'q':
				if (grid)
				{
					destroy_grid(grid);
					grid = NULL;
				}
				return;
			case 'e':
				if (grid)
				{
					n = 1;
					if (c->nargs >= 1)
						n = atoi(c->args[0]);
					for (i = 0; i < n; i++)
						evoluate_grid(grid, &conways, MODE_DEAD);
				}
				else
					printf("The grid must be initialized !\n");
				break;
			case 'g':
				if (c->nargs < 2)
					printf("%c command needs 2 arguments !\n", c->command);
				else
				{
					if (grid)
					{
						destroy_grid(grid);
						grid = NULL;
					}
					grid = generate_grid(atoi(c->args[0]), atoi(c->args[1]));
				}
				break;
			case 'p':
				if (c->nargs < 3)
					printf("%c command needs 3 arguments !\n", c->command);
				else
				{
					if (grid)
						grid->grid[atoi(c->args[0])][atoi(c->args[1])] = atoi(c->args[2]);
					else
						printf("The grid must be initialized !\n");
				}
				break;
			case 's':
				if (c->nargs < 1)
					printf("%c command needs 1 argument !\n", c->command);
				else
				{
					if (grid)
					{
						if (!(save_grid(grid, c->args[0])))
							printf("Couldn't save the file !\n");
					}
					else
						printf("The grid must be initialized !\n");
				}
				break;
			case 'r':
				if (c->nargs < 1)
					printf("%c command needs 1 argument !\n", c->command);
				else
				{
					if (grid)
					{
						t = 100;
						if (c->nargs >= 2)
							t = atoi(c->args[1]);
						n = atoi(c->args[0]);
						for (i = 0; i < n; i++)
						{
							evoluate_grid(grid, rule, MODE_DEAD);
							display_grid(grid);
							usleep(1000 * t);
						}

					}
				}
				break;
            case 'j':
                if (c->nargs < 1)
					printf("%c command needs 1 argument !\n", c->command);
                else
                    rule = c->args[0];
			default:
				printf("%c command does not exist !\n", c->command);

		}
		destroy_cmd(c);
	}
}

/*
 * Creates an t_cmd type from a raw command by copying it through malloc and
 * strcpy
 */
t_com	*create_cmd(char *raw)
{
	t_com *command;
	int i = 2;

	if (!(command = (t_com *)malloc(sizeof(t_com))))
		raise_error(ERR_MALLOC);
	if (!(command->args = (char **)malloc(100 * sizeof(char *))))
		raise_error(ERR_MALLOC);
	command->nargs = 0;
	if (!(command->raw_cmd = (char *)malloc(strlen(raw) * sizeof(char))))
		raise_error(ERR_MALLOC);
	strcpy(command->raw_cmd, raw);
	command->command = command->raw_cmd[0];
	while (command->raw_cmd[i])
	{
		command->args[command->nargs++] = command->raw_cmd + i;
		while (command->raw_cmd[i] != ' ' && command->raw_cmd[i] != '\n')
			i++;
		command->raw_cmd[i++] = '\0';
	}
	return (command);
}

/* 
 * Frees a t_cmd object
 */
void	destroy_cmd(t_com *cmd)
{
	free(cmd->raw_cmd);
	free(cmd);
}


/* 
 * Displays the prompt and allocates the user input
 */
t_com	*query_user(void)
{
	char buff[500];

	printf("> ");
	if (!(fgets(buff, sizeof(buff), stdin)))
		raise_error(ERR_OTHER);
	return (create_cmd(buff));
}
