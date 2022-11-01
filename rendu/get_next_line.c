#include "get_next_line.h"

void	gnl_resize_if_necessary(t_line *line, unsigned int count)
{
	size_t	occupied;

	if (!line->line)
		return ;
	occupied = line->index + 1;
	if (occupied + count > gnl_roundpow2(occupied))
		gnl_resize_line(line, gnl_roundpow2(occupied + count));
}

void	gnl_init_if_necessary(t_line *line, size_t count)
{
	if (!line->line && count > 0)
		line->line = malloc(sizeof(char) * INIT_LINE_SIZE);
}

void	gnl_append_from_stream(t_line *line, t_stream *s, unsigned int count)
{
	unsigned int	i;
	if (!line->line)
		return ;
	i = 0;
	while (i < count)
	{
		line->line[line->index + i] = s->buffer[s->cursor + i];
		printf("OK\n");
		i++;
	}
	line->line[i] = 0;
	line->index += count;
	s->cursor += count;
}

int	gnl_is_eol(t_line line)
{
	if (!line.line)
		return (1);
	assert(line.index > 0); //ATTENTION FORBIDDEN
	return (line.index > 0 && line.line[line.index - 1] == '\n');
}

unsigned int	gnl_chunk_size(t_stream s)
{
	int	i;

	i = 0;
	while (s.buffer[s.cursor + i] != '\n' && i < (s.bytes_read - s.cursor))
		i++;
	return ((unsigned int)i);
}

char	*get_next_line(int fd)
{
	static t_stream	s = {.cursor=0, .bytes_read=-42};
	t_line			line;
	unsigned int	count;

	line.line = 0;
	line.index = 0;
	while (s.bytes_read && s.bytes_read != -1)
	{
		count = gnl_chunk_size(s);
		gnl_init_if_necessary(&line, count);
		gnl_resize_if_necessary(&line, count);
		gnl_append_from_stream(&line, &s, count);
		if (gnl_is_eol(line))
			break ;
		s.bytes_read = read(fd, s.buffer, BUFFER_SIZE);
	}
	return (line.line);
}