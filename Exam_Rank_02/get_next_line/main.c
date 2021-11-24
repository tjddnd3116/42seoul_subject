#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int		r;
	char	*line;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{	
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	printf("%s", line);
	free(line);
	line = NULL;
}
