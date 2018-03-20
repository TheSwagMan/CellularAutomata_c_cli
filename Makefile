FLAGS = -W -Wall -Wextra -ansi -pedantic-errors -Werror -g
PARTS = game_of_life.c grid_utils.c file_utils.c utils.c gui.c evolving.c
OBJS = $(PARTS:.c=.o)
CC = gcc

NAME = game_of_life

all: $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $@ $^

%.o: %.c %.h
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -fr $(OBJS)

fclean: clean
	rm -fr $(NAME)

