#include "../tests.h"

static t_entire_file get_file_actual(char *file_name)
{
	t_entire_file 	f;
	int				fd;

	f.lines = malloc(1024 * sizeof(char *));
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

static t_entire_file get_file_expected(char *file_name)
{
	t_entire_file	f;
	FILE			*stream;
	size_t			linecapp;
	int				ret;

	f.lines = calloc(1024, sizeof(char *));
	f.i = 0;
	stream = fopen(file_name, "r");
	ret = getline(&(f.lines[f.i]), &linecapp, stream);
	while (ret != -1)
	{
		f.i++;
		ret = getline(&(f.lines[f.i]), &linecapp, stream);
	}
	free(f.lines[f.i]);
	f.lines[f.i] = 0;
	fclose(stream);
	(void)linecapp;
	return (f);
}

void test_entire_file(char *filename)
{
	t_entire_file actual;
	t_entire_file expected;
	int ret;

	expected = get_file_expected(filename);
	actual = get_file_actual(filename);
	if (expected.i != actual.i)
		printf("number of lines read differ: expected: %d vs actual: %d\n", expected.i, actual.i);
	assert(expected.i == actual.i);
	for(int j = 0; j < expected.i; j++)
	{
		if (!!expected.lines[j] != !!actual.lines[j])
		{
			printf("line #%d: expected: %s, actual: %s\n", j, expected.lines[j], actual.lines[j]);
		}
		assert(!!expected.lines[j] == !!actual.lines[j]);
		if (expected.lines[j])
		{
			ret = strcmp(expected.lines[j], actual.lines[j]);
			if (ret != 0)
				printf("line #%i: difference.\nexpected:%s\nactual:%s\n", j, expected.lines[j], actual.lines[j]);
			assert(ret == 0);
		}
	}
	printf("OK\n");
}

int main(int argc, char **argv)
{
	char *file_name = argv[1];
	printf("file: %s\n", file_name);
	test_entire_file(file_name);
	return (0);
}