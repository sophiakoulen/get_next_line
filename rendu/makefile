CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.
SRC = get_next_line.c get_next_line_utils.c
OBJS = get_next_line.o get_next_line_utils.o
NAME = libgnl.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $(OBJS)
	ranlib $@

BUF_SIZE=7

.c.o:
	$(CC) $(CFLAGS) -c -D BUFFER_SIZE=$(BUF_SIZE) $?

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
