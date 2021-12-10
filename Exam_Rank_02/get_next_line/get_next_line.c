#include "get_next_line.h"

char *get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*backup = NULL;
	int			i;
	char		*tmp;
	char		*line;

	i = 1;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!backup)
		backup = (char *)malloc(sizeof(char));
	while (!ft_strchr(backup, '\n'))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i <= 0)
			break ;
		buf[i] = '\0';
		tmp = ft_strjoin(backup, buf);
		free(backup);
		backup = tmp;
	}
	return (put_in_line(line, &backup, i, tmp));
}
