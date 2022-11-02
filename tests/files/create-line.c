#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>

int main()
{
	char c;
	int fd = open("huge-line.txt", O_CREAT | O_RDWR);
	printf("fd: %d\n", fd);
	for(int i = 0; i < 10000; i++)
	{
		c = i % 2 + 'A';
		write(fd, &c, 1);
	}
	close(fd);
}