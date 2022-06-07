/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InitMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:45:11 by soum              #+#    #+#             */
/*   Updated: 2022/06/07 20:37:51 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	jump_map(char *map_path)
{
	int		fd;
	char	*read_line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (fd);
	while (1)
	{
		read_line = get_next_line(fd);
		if (read_line[0] == '\n')
			break ;
		free(read_line);
	}
	free(read_line);
	while (1)
	{
		read_line = get_next_line(fd);
		if (read_line[0] == '\n')
			break ;
		free(read_line);
	}
	free(read_line);
	return (fd);
}

int	check_map(t_map *map_data, int fd)
{
	char	*read_line;

	map_data->cub_y = 0;
	while (1)
	{
		read_line = get_next_line(fd);
		if (!read_line)
			break ;
		map_data->cub_y++;
		free(read_line);
	}
	close(fd);
	map_data->map = (char **)malloc(sizeof(char *) * (map_data->cub_y + 1));
	if (!map_data->map)
		return (MAP_MALLOC_ERROR);
	map_data->map[map_data->cub_y] = NULL;
	return (0);
}

int	load_map(t_map *map_data, int fd)
{
	char	*read_line;
	int		idx;
	int		cub_x;

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

int	init_map(t_mlx_data *data)
{
	int		error;
	t_map	*map_data;
	char	*map_path;
	int		fd;

	error = 0;
	map_data = &data->map;
	map_data->cub_size = GRID;
	map_path = map_data->map_path;
	fd = jump_map(map_path);
	if (fd < 0)
		return (MAP_OPEN_ERROR);
	error = check_map(map_data, fd);
	if (error)
		return (error);
	map_data->cub_x = 0;
	fd = jump_map(map_path);
	if (fd < 0)
		return (MAP_OPEN_ERROR);
	error = load_map(map_data, fd);
	if (error)
		return (error);
	map_data->width = GRID * map_data->cub_x;
	map_data->height = GRID * map_data->cub_y;
	return (0);
}
