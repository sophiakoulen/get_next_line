#include "unit-tests.h"
#include "get_next_line.h"

void test_strncpy(void)
{
	char *src = "hello Worldydguywgdueudgy";
	char dst[1024];
	int j;
	for(int i = 0; i < 100; i++)
	{
		gnl_strncpy(dst, src, i);
		j = 0;
		while (src[j] && j < i)
		{
			assert(dst[j] == src[j]);
			j++;
		}
	}
}