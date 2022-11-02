#include "unit-tests.h"
#include "get_next_line.h"

void test_is_eol(void)
{
	t_line line;

	line.line = 0;
	line.index = 42;

	int ret = gnl_is_eol(line);
	assert(ret);

	line.line = "\n";
	line.index = 0;
	assert(!ret);
}