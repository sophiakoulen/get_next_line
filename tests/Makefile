CC=gcc
CFLAGS= -Wall -Wextra -I../src -L../src -g3 -fsanitize=address

FILES= files/emptyfile.txt files/hello-world.txt files/diff-lengths.txt \
files/multi-line-1.txt files/multi-line-2.txt files/multi-newline.txt \
files/one-newline.txt files/long-line.txt files/huge-line.txt files/17.txt \
files/10.txt files/10n.txt

GNL_FILES = get_next_line.c get_next_line_utils.c
GNL_PATH = ../src

all: tests-firstline tests-3lines tests-entire-file

get_next_line.c:
	cp $(GNL_PATH)/$@ $@

get_next_line_utils.c:
	cp $(GNL_PATH)/$@ $@

# testing reading 1 line
firstline: testcases/firstline.c $(GNL_FILES)
	$(CC) $(CFLAGS) $? -D BUFFER_SIZE=1 -o $@

tests-firstline: $(FILES) firstline
	echo "\ntesting reading 1 line\n"
	for filename in $(FILES) ; do \
		./firstline $$filename ; \
	done

# testing reading 3 lines
3lines: testcases/3-lines.c $(GNL_FILES)
	$(CC) $(CFLAGS) $? -D BUFFER_SIZE=10 -o $@

tests-3lines: $(FILES) 3lines
	echo "\n\ntesting reading 3 lines\n"
	for filename in $(FILES) ; do \
		./3lines $$filename ; \
	done

# testing reading entire file
entire-file: testcases/entire-file.c $(GNL_FILES)
	$(CC) $(CFLAGS) $? -D BUFFER_SIZE=10 -o $@

tests-entire-file: $(FILES) entire-file
	echo "\n\ntesting reading entire-file\n"
	for filename in $(FILES) ; do \
		./entire-file $$filename ; \
	done

# testing rmalloc errors

COUNT=0

malloc-error: testcases/malloc-error.c $(GNL_FILES)
	$(CC) $(CFLAGS) $? -D BUFFER_SIZE=18 -D COUNT=$(COUNT) -o $@

tests-malloc-error: $(FILES) malloc-error
	echo "\n\nwith malloc failure and count $(COUNT)\n"
	for filename in $(FILES) ; do \
		./malloc-error $$filename ; \
	done

#invalid fd

tests-invalid-fd: firstline
	echo "\n\ninvalid fd\n"
	./firstline "some-non-existent-file.txt"

fclean: 
	rm -f 3lines firstline entire-file malloc-error get_next_line.c get_next_line_utils.c

re: fclean all

ifndef VERBOSE
.SILENT:
endif

