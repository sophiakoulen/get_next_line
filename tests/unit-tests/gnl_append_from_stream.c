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

	unsigned int initial_index;
	unsigned int initial_cursor;

	char str[BUFFER_SIZE] = "Hello World\n***";
	memcpy(s.buffer, str, BUFFER_SIZE);

	for(unsigned int i = 0; i < 26; i++)
	{
		count = i;
		printf("count: %u\n", count);
		line.index = 5;
		allocated_for_line = count + line.index + 1 + 20;
		line.line = malloc(allocated_for_line);
		memset(line.line, '#', allocated_for_line);	

		assert(allocated_for_line >= count + line.index + 1);
		assert(line.index >= 0);
		
		allocated_for_stream = BUFFER_SIZE;
		s.bytes_read = BUFFER_SIZE;
		s.cursor = 0;

		assert(allocated_for_stream >= (unsigned int)s.bytes_read);
		assert(s.cursor >= 0 && s.cursor < s.bytes_read);
		assert(s.cursor + count <= (unsigned int)s.bytes_read);

		initial_cursor = s.cursor;
		initial_index = line.index;

		gnl_append_from_stream(&line, &s, count);

		//printf("initial cursor: %d, actual cursor: %u\n", initial_cursor, s.cursor);
		assert((unsigned int)s.cursor >= initial_cursor);
		assert(s.cursor <= s.bytes_read);
		assert(line.index >= initial_index);

		assert(line.line[line.index] == 0);

		assert(memcmp(line.line + initial_index, s.buffer + initial_cursor, count) == 0);
		assert(line.index - initial_index == count);

	}
	
}