#include "get_next_line.h"

/*int		gnl_ispow2(unsigned int n)
{
	return (!(n & (n - 1)));
}*/

uint32_t	gnl_roundpow2(uint32_t n)
{
	/*
		if n < 32, returns 32
		else
			if n is a pow 2, return n
			else, return nextpow2
	*/
	if (n < INIT_LINE_SIZE)
		return (INIT_LINE_SIZE);
	n--;
	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;
	n++;
	return (n);
}

void	gnl_strncpy(char *dst, char *src, size_t n)
{
	size_t				i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

/*void	*gnl_realloc(void *ptr, size_t s)
{
	void	*new_ptr;

	new_ptr = malloc(s);
	if (!new_ptr)
		return (0);
	if (ptr)
	{
		gnl_memcpy(new_ptr, ptr, s);
		free(ptr);
	}
	return (new_ptr);
}*/

__attribute__((weak)) void	gnl_resize_line(t_line *line, size_t new_size)
{
	char	*tmp;

	printf("not overwritten\n");
	tmp = malloc(sizeof(*tmp) * new_size);
	if (!tmp)
		free(line->line);
	else
	{
		gnl_strncpy(tmp, line->line, new_size);
		free(line->line);
	}
	line->line = tmp;
}