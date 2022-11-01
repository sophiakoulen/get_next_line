CC=gcc
CFLAGS= -Wall -Wextra -Werror -I../../rendu -L../../rendu

SRC= main.c gnl_roundpow2.c gnl_strncpy.c gnl_resize_line.c gnl_resize_if_necessary.c
OBJ=$(SRC:.c=.o)

test: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -lgnl -o $@

fclean:
	rm -f test

re: fclean test
