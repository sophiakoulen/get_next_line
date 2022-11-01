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

void	test_resize_line(void)
{
	t_line line;
	size_t new_size;

	line.line = malloc(sizeof(char) * 32);
	line.index = 12;

	new_size = 42;

	char phrase[1024] = "hello world !";

	strcpy(line.line, phrase);
	gnl_resize_line(&line, new_size);
	assert(strcmp(phrase, line.line) == 0);
}