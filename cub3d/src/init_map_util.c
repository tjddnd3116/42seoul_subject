/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:06:59 by soum              #+#    #+#             */
/*   Updated: 2022/09/07 17:41:17 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_config.h"

int	get_map_line(const char *path)
{
	int		fd;
	char	*read_line;
	int		map_line_num;

	map_line_num = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_handler(FILE_OPEN_ERROR);
	collect_fd_garbage(fd);
	while (1)
	{
		read_line = get_next_line(fd);
		if (!read_line || is_map(read_line))
			break ;
		map_line_num++;
		free(read_line);
	}
	if (!read_line)
		error_handler(MAP_FIND_ERROR);
	free(read_line);
	gnl_flush(fd);
	return (map_line_num);
}

int	jump_to_map(const char *path, int map_line_num)
{
	int		fd;
	char	*read_line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_handler(FILE_OPEN_ERROR);
	collect_fd_garbage(fd);
	while (map_line_num--)
	{
		read_line = get_next_line(fd);
		free(read_line);
	}
	return (fd);
}
