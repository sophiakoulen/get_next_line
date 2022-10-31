#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#ifndef BUFFER_SIZE
#	define BUFFER_SIZE 1
#endif
#define INIT_LINE_SIZE 32

typedef struct s_stream
{
	char	buffer[BUFFER_SIZE];
	int		cursor;
	int		bytes_read;
}	t_stream;

typedef	struct s_line
{
	char			*line;
	unsigned int	index;
}	t_line;

int		gnl_ispow2(unsigned int n);
void	gnl_memcpy(void *dst, const void *src, size_t n);
void	*gnl_realloc(void *ptr, size_t s);
int		gnl_attempt_resize(char **ptr, unsigned int index);

char	*get_next_line(int fd);

#endif