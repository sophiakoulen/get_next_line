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
	char	*ret;
	FILE	*f;
	size_t	linecapp;

	f = fopen(file_name, "r");
	ret = 0;
	getline(&ret, &linecapp, f);
	fclose(f);
	(void)linecapp;
	return (ret);
}

void test_firstline(char *filename)
{
	char *actual;
	char *expected;

	expected = first_line_expected(filename);
	actual = first_line_actual(filename);
	int ret = strcmp(expected, actual);
	if (ret != 0)
		printf("actual: %sEND\nexpected: %sEND\n", actual, expected);
	assert(ret == 0);
	printf("OK\n");
}

int main(int argc, char **argv)
{
	char *file_name = argv[1];
	printf("file: %s\n", file_name);
	test_firstline(file_name);
	return (0);
}