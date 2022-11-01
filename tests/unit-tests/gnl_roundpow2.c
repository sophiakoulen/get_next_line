#include "get_next_line.h"
#include "unit-tests.h"

void	test_roundpow2(void)
{
	uint32_t actual, expected;
	for(uint32_t i = 0; i < ((uint32_t)1 << 20); i++)
	{
		actual = gnl_roundpow2(i);
		assert(actual >= i);
		if (i <= INIT_LINE_SIZE)
		{
			expected = INIT_LINE_SIZE;
		}
		else if (__builtin_popcount(i) == 1)
		{
			expected = i;
		}
		else
		{
			expected = 1 << (32 - __builtin_clzl(i));
		}
		if (actual != expected)
		{
			printf("actual: %u, expected: %u\n", actual, expected);
		}
		assert(actual == expected);
	}
}