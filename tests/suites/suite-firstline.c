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

void test_firstline_emptyfile(void)
{
	test_firstline("files/emptyfile.txt");
}

void test_firstline_helloworld(void)
{
	test_firstline("files/hello-world.txt");
}

void test_firstline_multiline1(void)
{
	test_firstline("files/multi-line-1.txt");
}

void test_firstline_multiline2(void)
{
	test_firstline("files/multi-line-2.txt");
}

void test_firstline_multinewline(void)
{
	test_firstline("files/multi-newline.txt");
}

void test_firstline_onenewline(void)
{
	test_firstline("files/one-newline.txt");
}

void test_firstline(char *filename)
{
	char *actual;
	char *expected;

	expected = first_line_expected(filename);
	actual = first_line_actual(filename);
	CU_ASSERT_STRING_EQUAL(actual, expected);
}