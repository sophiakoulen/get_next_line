#include "../tests.h"
#include <errno.h>
#include <dlfcn.h>

static int	count = COUNT;

void	*malloc(size_t size)
{
	static void *(*real_malloc)(size_t) = NULL;

	if (real_malloc == NULL)
	{
		real_malloc = (void *(*)(size_t))dlsym(RTLD_NEXT, "malloc");
	}

	if (count == 0)
	{
		return (NULL); 
	}
	else
	{
		count--;
		return (real_malloc(size));
	}
}

static t_entire_file get_file_actual(char *file_name)
{
	t_entire_file 	f;
	int				fd;

	f.lines = calloc(1024, sizeof(char *));
	f.i = 0;
	fd = open(file_name, O_RDWR);
	f.lines[f.i] = get_next_line(fd);
	while (f.lines[f.i])
	{
		f.i++;
		f.lines[f.i] = get_next_line(fd);
	}
	close(fd);
	return (f);
}

int main(int argc, char **argv)
{
	printf("file: %s\n", argv[1]);
	get_file_actual(argv[1]);
	printf("OK\n");
	return (0);
}