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
	char	**lines;
	FILE	*f;
	size_t	linecapp;
	int		ret;

	lines = calloc(3, sizeof(*lines));
	f = fopen(file_name, "r");
	for(int i = 0; i < 3; i++)
	{
		ret = getline(&(lines[i]), &linecapp, f);
		if (ret == -1)
		{
			free(lines[i]);
			lines[i] = 0;
		}
	}
	fclose(f);
	(void)linecapp;
	return (lines);
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
		if (!!expected[i] != !!actual[i])
			printf("line #%d: expected: %s, actual: %s", i, expected[i], actual[i]);
		assert(!!expected[i] == !!actual[i]);
		if (expected[i])
		{
			ret = strcmp(expected[i], actual[i]);
			if (ret != 0)
				printf("expected:%s\nactual:%s\n", expected[i], actual[i]);
			assert(ret == 0);
		}
	}
}

int main(int argc, char **argv)
{
	char *file_name = argv[1];
	printf("file: %s\n", file_name);
	printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
	test_3lines(file_name);
	return (0);
}