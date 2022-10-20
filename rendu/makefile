CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.
SRC = get_next_line.c
OBJS = get_next_line.o
NAME = libgnl.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $(OBJS)
	ranlib $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
