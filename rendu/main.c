#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int fd = open("text.txt", O_RDWR);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	close(fd);
}