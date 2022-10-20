CC=gcc
CFLAGS= -I/Users/skoulen/.brew/Cellar/cunit/2.1-3/include -L/Users/skoulen/.brew/Cellar/cunit/2.1-3/lib -I../rendu -L../rendu
NAME=test
SRC= main.c suites/suite-firstline.c

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -lcunit -lgnl -o $@

fclean:
	rm $(NAME)

re: fclean all

FILES= files/emptyfile.txt files/hello-world.txt files/multi-line-1.txt files/multi-line2.txt files/multi-newline.txt files/one-newline.txt

firstline: 