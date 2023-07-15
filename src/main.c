#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Usage: ./get_next_line <../tests/xxx1.txt> <../tests/xxx2.txt>\n");
		return (0);
	}

	ssize_t	fd = open(argv[1], O_RDONLY);
	char	*arr;

// don't try to read the long line tests, stack smashing should be detected. This is just
// to test that get_next_line works. To test large lines, either malloc char [line], or
// test get_next_line by itself or against another get_next_line, or any other method you
// can think of. I am DONE here, as much as I loved the shit out it. pshhhhhh. love ya x

	while ((arr = get_next_line(fd)))
	{
		printf("%s", arr);
	}
	else
		return 1;
	close(fd);
	return 0;
}
