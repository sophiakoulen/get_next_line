#include "get_next_line.h"
#include "unit-tests.h"

void	test_append_from_stream(void)
{
	/* conditions on using this function 

		the line must have enough space available for count
		characters. That means the allocated memory must be >= 
		count + line.index + 1;

		the stream must have at least stream.bytes_read bytes allocated
		the cursor must be >= 0 and < stream.bytes_read
		cursor + count must be <= stream.bytes_read 
		stream.buffer needn't be nul-terminated
	*/

	t_line			line;
	t_stream		s;
	unsigned int	count;
	unsigned int	allocated_for_line;
	unsigned int	allocated_for_stream;

	for()
	{
		assert(allocated_for_line >= count + line.index + 1);
		assert(line.index >= 0);
		
		assert(allocated_for_stream >= s.bytes_read);
		assert(s.cursor >= 0 && s.cursor < s.bytes_read);
		assert(s.cursor + count <= s.bytes_read);
	}

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