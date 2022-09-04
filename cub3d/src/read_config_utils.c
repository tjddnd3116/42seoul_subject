/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_config_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:07:18 by soum              #+#    #+#             */
/*   Updated: 2022/09/04 15:07:18 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_config.h"

void	free_splited_arr(char **splited_words)
{
	int	idx;

	idx = 0;
	while (splited_words[idx])
	{
		free(splited_words[idx]);
		idx++;
	}
	free(splited_words);
	collect_ptr_2d_garbage(NULL);
}

int	count_splited_words(char **splited_words)
{
	int	cnt;

	cnt = 0;
	while (splited_words[cnt])
		cnt++;
	return (cnt);
}

char	*remove_newline(char *read_line)
{
	char	*ret;

	if (!read_line || !ft_strncmp(read_line, "\n", 1))
		return (read_line);
	ret = ft_substr(read_line, 0, ft_strlen(read_line) - 1);
	free(read_line);
	return (ret);
}

void	gnl_flush(int fd)
{
	char	*read_line;

	read_line = get_next_line(fd);
	while (read_line)
	{
		free(read_line);
		read_line = get_next_line(fd);
	}
	close(fd);
	collect_fd_garbage(0);
}
