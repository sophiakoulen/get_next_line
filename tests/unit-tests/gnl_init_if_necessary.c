#include "get_next_line.h"
#include "unit-tests.h"
#include <dlfcn.h>

/*void	*malloc(size_t size)
{
	static void *(*real_malloc)(size_t) = NULL;
	void	*ret;
	if (real_malloc == NULL)
	{
		real_malloc = (void *(*)(size_t))dlsym(RTLD_NEXT, "malloc");
	}
	ret = real_malloc(size);
	printf("%p - malloc of size: %zu\n", ret, size);
	return (ret);
}

void	free(void *ptr)
{
	static void (*real_free)(void *) = NULL;
	if (real_free == NULL)
	{
		real_free = (void (*)(void *))dlsym(RTLD_NEXT, "free");
	}
	printf("%p - is free\n", ptr);
	real_free(ptr);
}*/

void	test_init_if_necessary(void)
{
	t_line			line;

	for(unsigned int i = 0; i < 1 << 2; i++)
	{
		line.line = 0;
		char *old = line.line;
		gnl_init_if_necessary(&line, i);
		printf("line.line: %p\n", line.line);
		if (i == 0)
		{
			assert(!line.line);
			assert(line.line == old);
		}
		else
		{
			assert(line.line);
		}
	}
/*
	for(unsigned int i = 0; i < 1 << 2; i++)
	{
		line.line = malloc(1);
		gnl_init_if_necessary(&line, i);
		assert(line.line);
	}
	*/
}