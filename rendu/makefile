CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -L. -g3 -fsanitize=address

SRC = main.c get_next_line.c

test: $(SRC)
	gcc $(SRC) -o $@