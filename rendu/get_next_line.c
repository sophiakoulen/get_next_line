/*typedef	struct s_string
{
	size_t	index;
	size_t	max_size;
	char	*ptr;	
}	t_string;

#define INIT_SIZE 32

char	*string_init(t_string *s)
{
	s->index = 0;
	s->max_size = INIT_SIZE - 1;
	s->ptr = malloc((max_size + 1) * sizeof(char));
	return (s->ptr);
}

void	*ft_realloc(void *ptr, size_t size)
{

}

char	*string_append(t_string *s, char c)
{
	if (s->index == s->max_size)
	{
		s->max_size = s->max_size * 2 + 1;
		s->ptr = ft_realloc(s->ptr, (max_size + 1) * sizeof(char));
	}
	(s->ptr)[s->index] = c;
	(s->ptr)[s->index + 1] = 0;
	(s->index)++;
}

*/

#include "get_next_line.h"

#define BUFFER_SIZE 1
#define LINE_SIZE 1024

char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	static int	i;
	static int ret;
	static int first_call = 1;

	char			*line;
	unsigned int	j;
	unsigned int	max_line_size = LINE_SIZE;
	
	line = malloc(max_line_size);
	j = 0;
	if (first_call)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		first_call = 0;
	}
	while (ret)
	{
		while (i < ret)
		{
			line[j] = buffer[i];
			i++;
			if (line[j] == '\n')
			{
				line[j + 1] = 0;
				return (line);
			}
			j++;
		}
		ret = read(fd, buffer, BUFFER_SIZE);
		i = 0;
	}
	line[j] = 0;
	return (line);
}