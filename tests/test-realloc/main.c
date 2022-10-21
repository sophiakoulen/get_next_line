#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main()
{
	int *ptr;

	ptr = malloc(32);
	int *tmp = gnl_realloc(ptr, 64);
	ptr = tmp;
	tmp = gnl_realloc(ptr, 128);
	return (0);
}