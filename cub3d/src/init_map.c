/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:06:57 by soum              #+#    #+#             */
/*   Updated: 2022/09/04 15:06:58 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_data.h"
#include <string.h>

static void	get_map_size(int fd, t_mlx_data *mlx_data);
static void	load_map(int fd, t_mlx_data *mlx_data);

void	init_map(const char *path, t_mlx_data *mlx_data)
{
	int		map_line_num;

	mlx_data->player.grid = (t_ivec2){-1, -1};
	map_line_num = get_map_line(path);
	get_map_size(jump_to_map(path, map_line_num), mlx_data);
	load_map(jump_to_map(path, map_line_num), mlx_data);
	if (check_map_validity(mlx_data->map.map, mlx_data->map.height,
			mlx_data->map.width, &mlx_data->player.grid))
		error_handler(MAP_INVALID_ERROR);
}

void	get_map_size(int fd, t_mlx_data *mlx_data)
{
	char	*read_line;
	int		max_map_width;

	max_map_width = 0;
	while (1)
	{
		read_line = remove_newline(get_next_line(fd));
		collect_ptr_garbage((void *)read_line);
		if (!read_line)
			break ;
		if (!is_map_line(read_line))
			error_handler(MAP_INVALID_ERROR);
		mlx_data->map.height++;
		max_map_width = ft_strlen(read_line);
		if (max_map_width >= mlx_data->map.width)
			mlx_data->map.width = max_map_width;
		free(read_line);
	}
	mlx_data->map.map = (uint32_t **)malloc(sizeof(uint32_t *)
			* (mlx_data->map.height + 1));
	if (!mlx_data->map.map)
		error_handler(MALLOC_ERROR);
	close(fd);
	mlx_data->map.map[mlx_data->map.height] = NULL;
}

void	load_map(int fd, t_mlx_data *mlx_data)
{
	char		*read_line;
	uint32_t	*map_line;
	int			idx;
	int			jdx;

	idx = 0;
	while (1)
	{
		read_line = remove_newline(get_next_line(fd));
		if (!read_line)
			break ;
		map_line = ft_calloc(1, sizeof(uint32_t) * mlx_data->map.width);
		jdx = 0;
		while (read_line[jdx])
		{
			map_line[jdx] = read_line[jdx];
			++jdx;
		}
		while (jdx < mlx_data->map.width)
			map_line[jdx++] = ' ';
		mlx_data->map.map[idx++] = map_line;
		free(read_line);
	}
	close(fd);
	collect_fd_garbage(0);
}
