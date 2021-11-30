/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:09:41 by soum              #+#    #+#             */
/*   Updated: 2021/11/29 19:32:34 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*tmp;
	int		str1_len;
	int		str2_len;
	int		i;
	int		j;

	j = 0;
	i = 0;
	str1_len = ft_strlen(str1);
	str2_len = ft_strlen(str2);
	tmp = (char *)malloc(sizeof(char) * (str1_len + str2_len + 1));
	while (str1[i])
	{
		tmp[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		tmp[i] = str2[j];
		i++;
		j++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_strchr(char *backup, char let)
{
	int	index;

	index = 0;
	while (backup[index])
	{
		if (backup[index] == let)
			return (&backup[index]);
		else
			index++;
	}
	return (NULL);
}

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

char	*ft_strdup(char *str)
{
	char	*tmp;
	int		str_len;
	int		index;

	index = 0;
	str_len = ft_strlen(str);
	tmp = (char *)malloc(sizeof(char) * str_len + 1);
	while (str[index])
	{
		tmp[index] = str[index];
		index++;
	}
	tmp[index] = '\0';
	return (tmp);
}

char	*ft_substr(char *str, int start, int len)
{
	char	*tmp;
	int		index;

	index = 0;
	if (str == NULL)
		return (NULL);
	tmp = (char *)malloc(sizeof(char) * len + 1);
	if (!tmp)
		return (NULL);
	while (index < len && str[start + index])
	{
		tmp[index] = str[start + index];
		index++;
	}
	tmp[index] = 0;
	return (tmp);
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
		backup = (char *)malloc(sizeof(char));
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
