#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	ssize_t fd;
	ssize_t	fd_2;
	char	*arr;
	char	*str;

	if (argc < 2)
	{
		printf("Please enter file name:\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	fd_2 = open(argv[2], O_RDONLY);
	while ((arr = get_next_line(fd)))
	{
		if ((str = get_next_line(fd_2)))
			printf("%s", str);
		printf("%s", arr);
	}
	while ((str = get_next_line(fd_2)))
		printf("%s", str);
	close(fd_2);
	close(fd);
	return 0;
}
