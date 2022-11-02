#include "unit-tests.h"
#include "get_next_line.h"

void test_chunk_size(void)
{
	t_stream s;
	unsigned int actual, expected;

	char str[BUFFER_SIZE] = "Hello World\n";

	memcpy(s.buffer, str, BUFFER_SIZE);
	s.cursor = 0;
	s.bytes_read = BUFFER_SIZE;

	expected = 12;
	actual = gnl_chunk_size(s);

	printf("expected: %u, actual %u\n", expected, actual);

	assert(actual == expected);
}