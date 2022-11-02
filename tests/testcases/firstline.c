#include "../tests.h"

static char *first_line_actual(char *file_name)
{
	char	*ret;
	int		fd;

	fd = open(file_name, O_RDWR);
	ret = get_next_line(fd);
	close(fd);
	return (ret);
}

static char *first_line_expected(char *file_name)
{
	char	*line;
	FILE	*f;
	size_t	linecapp;
	int 	ret;

	f = fopen(file_name, "r");
	if (!f)
		return (0);
	line = 0;
	ret = getline(&line, &linecapp, f);
	if (ret == -1)
	{
		free(line);
		return (0);
	}
	fclose(f);
	(void)linecapp;
	return (line);
}

void test_firstline(char *filename)
{
	char *actual;
	char *expected;

	expected = first_line_expected(filename);
	actual = first_line_actual(filename);
	if (!!expected != !!actual)
	{
		printf("expected: %s", expected);
		printf("actual: %s", actual);
	}
	assert(!!expected == !!actual);
	if (expected)
	{
		int ret = strcmp(expected, actual);
		if (ret != 0)
			printf("actual: %s\nexpected: %s\n", actual, expected);
		assert(ret == 0);
	}
}

int main(int argc, char **argv)
{
	char *file_name = argv[1];
	printf("file: %s\n", file_name);
	printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
	test_firstline(file_name);
	return (0);
}