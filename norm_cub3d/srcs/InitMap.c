/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InitMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:45:11 by soum              #+#    #+#             */
/*   Updated: 2022/06/03 14:45:16 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_map(t_map *map_data, char *map_path)
{
	int		fd;
	char	*read_line;

	map_data->cub_y = 0;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (MAP_OPEN_ERROR);
	while (1)
	{
		read_line = get_next_line(fd);
		if (!read_line)
			break ;
		map_data->cub_y++;
		free(read_line);
	}
	close(fd);
	return (0);
}

int	load_map(t_map *map_data, char *map_path)
{
	int		fd;
	char	*read_line;
	int		idx;
	int		cub_x;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (MAP_OPEN_ERROR);
	map_data->map = (char **)malloc(sizeof(char *) * (map_data->cub_y + 1));
	if (!map_data->map)
		return (MAP_MALLOC_ERROR);
	map_data->map[map_data->cub_y] = NULL;
	idx = 0;
	while (1)
	{
		read_line = get_next_line(fd);
		if (!read_line)
			break ;
		map_data->map[idx++] = read_line;
		cub_x = ft_strlen(read_line) - 1;
		if (cub_x >= map_data->cub_x)
			map_data->cub_x = cub_x;
	}
	close(fd);
	return (0);
}

int	init_map(t_mlx_data *data, char *map_path)
{
	int		error;
	t_map	*map_data;

	data->map = (t_map *)malloc(sizeof(t_map) * 1);
	map_data = data->map;
	map_data->cub_size = GRID;
	error = check_map(map_data, map_path);
	if (error)
		return (error);
	data->map->cub_x = 0;
	error = load_map(map_data, map_path);
	if (error)
		return (error);
	data->map->width = GRID * data->map->cub_x;
	data->map->height = GRID * data->map->cub_y;
	return (0);
}
