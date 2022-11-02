#include "get_next_line.h"
#include "unit-tests.h"

int		g_resized;
size_t	g_new_size;

/*void	gnl_resize_line(t_line *line, size_t new_size)
{
	(void)line;
	g_new_size = new_size;
	g_resized = 1;
}*/

static unsigned int get_capacity(t_line line)
{
	return (gnl_roundpow2(line.index + 1));
}

static unsigned int get_needed(t_line line, unsigned int count)
{
	return (line.index + 1 + count);
}

void	test_resize_if_necessary(void)
{
	t_line			line;
	unsigned int	count, capacity, needed;

	line.line = malloc(1);
	for(unsigned int i = 0; i < (1U << 3); i++)
	{
		line.index = i;
		for(unsigned int j = 0; j < (1U << 12); j++)
		{
			count = j;
			g_resized = 0;
			g_new_size = -1;
			capacity = get_capacity(line);
			needed = get_needed(line, count);
			gnl_resize_if_necessary(&line, count);
			if (needed > capacity)
			{
				assert(g_resized);
				capacity = g_new_size;
				printf("new capacity: %u\n", capacity);
				assert(capacity >= needed);
			}
		}
		printf("\n");
	}
}