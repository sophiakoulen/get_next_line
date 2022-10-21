#include "get_next_line.h"

int		gnl_attempt_resize(char **ptr, unsigned int index)
{
	char	*tmp;

	if (index >= (INIT_LINE_SIZE - 1) && gnl_ispow2(index + 1))
	{
		tmp = gnl_realloc(*ptr, 2 * (index + 1) * sizeof(char));
		if (!tmp)
		{
			free(*ptr);
			return (0);
		}
		*ptr = tmp;
	}
	return (1);
}

int		gnl_consume_buffer(t_stream *s, char **line, unsigned int *j, int fd)
{
	while (s->cursor < s->bytes_read)
	{
		(*line)[*j] = s->buffer[s->cursor];
		(*line)[*j + 1] = 0;
		s->cursor++;
		if ((*line)[*j] == '\n')
			return (1);
		(*j)++;
		if (!gnl_attempt_resize(line, (*j)))
			return (0);
	}
	s->bytes_read = read(fd, s->buffer, BUFFER_SIZE);
	s->cursor = 0;
	return (1);
}

char	*get_next_line(int fd)
{
	static t_stream	s = {.cursor=0, .bytes_read=-42};
	char			*line;
	unsigned int	j;

	line = malloc(INIT_LINE_SIZE);
	if (!line)
		return (0);

	j = 0;
	while (s.bytes_read && s.bytes_read != -1)
	{
		if (!gnl_consume_buffer(&s, &line, &j, fd))
			return (0);
		if (line[j] == '\n')
			return (line);
	}
	if (j == 0)
	{
		free(line);
		return (0);
	}
	return (line);
}