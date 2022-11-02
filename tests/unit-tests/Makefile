CC=gcc
CFLAGS= -Wall -Wextra -Werror -I../../src -L../../src

SRC= main.c gnl_roundpow2.c gnl_strncpy.c gnl_resize_line.c \
gnl_resize_if_necessary.c gnl_init_if_necessary.c \
gnl_append_from_stream.c gnl_is_eol.c gnl_chunk_size.c
OBJ=$(SRC:.c=.o)

BUF_SIZE =25

test: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -D BUFFER_SIZE=$(BUF_SIZE) -lgnl -fsanitize=address -o $@

fclean:
	rm -f test

re: fclean test
