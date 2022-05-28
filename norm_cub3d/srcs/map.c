/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:45:11 by soum              #+#    #+#             */
/*   Updated: 2022/05/28 23:21:24 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_map(int fd)
{
	return (fd);
}

void	load_map(t_map *map_data, int fd)
{
	int		height;
	int		width;
	char	*tmp;

	height = 0;
	while (1)
	{
		height++;
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		width = ft_strlen(tmp);
	}
	map_data->width = width;
	map_data->height = height;
}

int	init_map(t_map *map_data, char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (0);
	load_map(map_data, fd);
	check_map(fd);
	close(fd);
	return (0);
}
