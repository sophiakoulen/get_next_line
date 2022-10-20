#include "../tests.h"
#include <errno.h>
#include <dlfcn.h>

static int	malloc_fail_code = 1;

void	*malloc(size_t size)
{
	static void *(*real_malloc)(size_t) = NULL;

	if (real_malloc == NULL)
	{
		real_malloc = (void *(*)(size_t))dlsym(RTLD_NEXT, "malloc");
	}

	if (malloc_fail_code != 0)
	{
		errno = malloc_fail_code;
		malloc_fail_code = 0;
		return (NULL); 
	}

	return (real_malloc(size));
}

int main()
{
	printf("overriding malloc\n");
	char *line;
	int fd = open("testcases/test.txt", O_RDWR);
	line = get_next_line(fd);
	close(fd);
	printf("%p", line);
	return (0);
}