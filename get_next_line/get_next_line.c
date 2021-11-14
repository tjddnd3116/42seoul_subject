/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 12:35:33 by soum              #+#    #+#             */
/*   Updated: 2021/07/14 19:40:38 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	del_backup(char **backup)
{
	if (*backup)
	{
		free(*backup);
		*backup = NULL;
		return (1);
	}
	return (0);
}

char	*put_in_line(char *line, char **backup, int i, char *tmp)
{
	if (i == 0)
		line = ft_strdup(*backup);
	else if (i > 0)
		line = ft_substr(*backup, 0, (ft_strchr(*backup, '\n') - *backup + 1));
	else
	{
		del_backup(&line);
		del_backup(backup);
		return (NULL);
	}
	tmp = ft_strdup(*backup + ft_strlen(line));
	del_backup(backup);
	*backup = tmp;
	if (i == 0 && ft_strlen(line) == 0)
	{
		del_backup(&line);
		del_backup(backup);
		return (NULL);
	}
	if (i == 0)
		del_backup(backup);
	return (line);
}

char	*ft_malloc(size_t size)
{
	char	*ptr;
	size_t	index;

	index = 0;
	ptr = (char *)malloc(size);
	if (!ptr)
		return (NULL);
	while (index < size)
	{
		ptr[index] = 0;
		index++;
	}
	return (ptr);
}

char	*get_next_line(int fd)
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
		backup = ft_malloc(1);
	while (!(ft_strchr(backup, '\n')))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i <= 0)
			break ;
		buf[i] = '\0';
		tmp = ft_strjoin(backup, buf);
		del_backup(&backup);
		backup = tmp;
	}
	return (put_in_line(line, &backup, i, tmp));
}
