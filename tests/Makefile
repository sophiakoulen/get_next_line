CC=gcc
CFLAGS= -I../rendu -L../rendu
FILES= files/emptyfile.txt files/hello-world.txt files/multi-line-1.txt files/multi-line-2.txt files/multi-newline.txt files/one-newline.txt files/long-line.txt

all: tests-firstline tests-3lines

# testing reading 1 line
firstline: testcases/firstline.c
	$(CC) $(CFLAGS) -g3 -fsanitize=address $? -lgnl -o $@

tests-firstline: $(FILES) firstline
	echo "\ntesting reading 1 line\n"
	for filename in $(FILES) ; do \
		./firstline $$filename ; \
	done

# testing reading 3 lines
3lines: testcases/3-lines.c
	$(CC) $(CFLAGS) -g3 -fsanitize=address $? -lgnl -o $@

tests-3lines: $(FILES) 3lines
	echo "\n\ntesting reading 3 lines\n"
	for filename in $(FILES) ; do \
		./3lines $$filename ; \
	done

fclean: 
	rm -f 3lines firstline

re: fclean all

ifndef VERBOSE
.SILENT:
endif
