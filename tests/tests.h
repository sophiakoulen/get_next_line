#ifndef TESTS_H
# define TESTS_H

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include "get_next_line.h"

void test_firstline_emptyfile(void);
void test_firstline_helloworld(void);
void test_firstline_multiline1(void);
void test_firstline_multiline2(void);
void test_firstline_multinewline(void);
void test_firstline_onenewline(void);
void test_firstline(char *filename);

#endif