#include "get_next_line.h"
#include "unit-tests.h"

void	test_append_from_stream(void)
{
	t_line			line;
	t_stream		s;
	unsigned int	count;

	line.line = "AAAAAAAAAAAAAAAA";
	line.index = 0;

	char str[BUFFER_SIZE] = 

	s.buffer = 
	s.bytes_read = 5;
	s.cursor = 0;

	count = 4;

	unsigned int initial_index = line.index;
	unsigned int initial_cursor = s.cursor;
	gnl_append_from_stream(&line, &s, count);

	assert((unsigned int)s.cursor >= initial_cursor);
	assert(s.bytes_read - (unsigned int)s.cursor >= count);
	assert(line.index >= initial_index);
	assert(line.line[line.index] == 0);
	assert(memcmp(line.line + initial_index, s.buffer + initial_cursor, count) == 0);
	assert(line.index - initial_index == count);
	
}