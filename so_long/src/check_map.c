/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 03:48:42 by soum              #+#    #+#             */
/*   Updated: 2021/11/01 15:35:15 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_map_line(char *line, t_map *map)
{
	int	index;

	index = -1;
	if (line[0] != '1')
		return (0);
	while (line[++index] != '\n')
	{
		if (ft_strchr(MAP, line[index]) == NULL)
			return (0);
		if (line[index] != '1' || map->all_wall == 0)
			map->all_wall = 0;
		if (line[index] == 'C')
			map->is_C++;
		else if (line[index] == 'E')
			map->is_E++;
		else if (line[index] == 'P')
			map->is_P++;
	}
	if (map->len == -1)
		map->len = index;
	if (map->len != index)
		return (0);
	if (line[--index] != '1')
		return (0);
	return (1);
}

int	check_map(int fd, t_map *map, t_window *window)
{
	char	*tmp;
	int		line;
	int		error;

	error = 1;
	line = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		map->all_wall = 1;
		error = check_map_line(tmp, map);
		free(tmp);
		if (error == 0)
			return (0);
		if (line == 0 && map->all_wall != 1)
			return (0);
		line++;
	}
	if (line <= 2 || map->all_wall != 1)
		return (0);
	window->map_y = line;
	window->map_x = map->len;
	return (1);
}

void	init_map(t_map *map)
{
	map->is_P = 0;
	map->is_C = 0;
	map->is_E = 0;
	map->len = -1;
}

int	check_ber(t_window *window, char *ber)
{
	int		fd;
	int		error;
	t_map	*map;

	map = malloc(sizeof(t_map) * 1);
	if (!map)
		error_msg_exit("map check alloc error");
	init_map(map);
	fd = open(ber, O_RDONLY);
	error = check_map(fd, map, window);
	if (map->is_P != 1 || map->is_C == 0 | map->is_E == 0)
		error = 0;
	window->exit_count = map->is_E;
	window->item_count = map->is_C;
	free(map);
	return (error);
}
