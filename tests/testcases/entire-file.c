#include "../tests.h"

static char **lines3_actual(char *file_name)
{
	char	**ret;
	int		fd;

	ret = malloc(3 * sizeof(char *));
	fd = open(file_name, O_RDWR);
	for(int i = 0; i < 3; i++)
		ret[i] = get_next_line(fd);
	close(fd);
	return (ret);
}

static char **lines3_expected(char *file_name)
{
	char	**ret;
	FILE	*f;
	size_t	linecapp;

	ret = calloc(3, sizeof(*ret));
	f = fopen(file_name, "r");
	for(int i = 0; i < 3; i++)
	{
		getline(&(ret[i]), &linecapp, f);
	}
	fclose(f);
	(void)linecapp;
	return (ret);
}

void test_3lines(char *filename)
{
	char **actual;
	char **expected;
	int ret;

	expected = lines3_expected(filename);
	actual = lines3_actual(filename);
	for(int i = 0; i < 3; i++)
	{
		ret = strcmp(expected[i], actual[i]);
		if (ret != 0)
			printf("expected:%s\nactual:%s\n", expected[i], actual[i]);
		assert(ret == 0);
	}
	printf("OK\n");
}

int main(int argc, char **argv)
{
	char *file_name = argv[1];
	printf("file: %s\n", file_name);
	test_3lines(file_name);
	return (0);
}