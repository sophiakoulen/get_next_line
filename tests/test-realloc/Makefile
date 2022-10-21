CC=gcc
CFLAGS= -Wall -Wextra -g3 -fsanitize=address -I../../rendu -L../../rendu
SRC=main.c

all: test

test: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -lgnl -o test