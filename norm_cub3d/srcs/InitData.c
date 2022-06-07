/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InitData.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:20:58 by soum              #+#    #+#             */
/*   Updated: 2022/06/06 13:42:38 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_mlx_data(t_screen *screen)
{
	printf("----[mlx data]----\n");
	printf("screen w : %d , screen h : %d\n", screen->screen_w, \
			screen->screen_h);
	printf("----[mlx data]----\n");
}

void	print_map_data(t_map *map)
{
	int	idx;

	idx = 0;
	printf("---[map data]----\n");
	while (map->map[idx])
		printf("%s", map->map[idx++]);
	printf("map grid width : %d, map grid height : %d\n", \
			map->width, map->height);
	printf("---[map data]----\n");
}

void	print_player_data(t_player *player)
{
	printf("---[player data]----\n");
	printf("mid pos x: %d, y: %d\n", player->mid_pos[0], player->mid_pos[1]);
	printf("grid x: %d, y: %d\n", player->grid[0], player->grid[1]);
	printf("angle : %d\n", player->angle);
	printf("---[player data]----\n");
}

void	print_point_data(t_point *point)
{
	printf("---[point data]----\n");
	printf("x pos : %f, y pos : %f\n", point->map_x, point->map_y);
	printf("x grid : %d, y grid : %d\n", point->grid_x, point->grid_y);
	printf("player to wall len : %f\n", point->wall_len);
	printf("angle : %f\n", point->angle);
	printf("---[point data]----\n");
}

void	init_data(t_mlx_data *data, char *map_path)
{
	init_map(data, map_path);
	/** print_map_data(data->map); */
	init_screen(data);
	init_img(data);
	init_txt(data);
	/** print_mlx_data(&data->screen); */
	init_player(data);
	/** print_player_data(&data->player); */
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
}
