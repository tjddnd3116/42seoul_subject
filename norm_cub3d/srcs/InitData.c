/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InitData.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:20:58 by soum              #+#    #+#             */
/*   Updated: 2022/06/08 15:43:10 by soum             ###   ########.fr       */
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
	printf("cub_x : %d, cub_y : %d\n", \
			map->cub_x, map->cub_y);
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

void	print_fc_data(t_texture *text)
{
	char	**floor;
	char	**ceiling;
	int		idx;

	floor = text->floor_txt;
	ceiling = text->ceiling_txt;
	idx = 0;
	while (floor[idx])
	{
		printf("floor : %s\n", floor[idx]);
		idx++;
	}
	idx = 0;
	while (ceiling[idx])
	{
		printf("ceiling : %s\n", ceiling[idx]);
		idx++;
	}
}

void	print_wall_txt_data(t_texture *text)
{
	printf("N :%s\n", text->n_wall_path);
	printf("S :%s\n", text->s_wall_path);
	printf("W :%s\n", text->w_wall_path);
	printf("E :%s\n", text->e_wall_path);
}

void	init_data(t_mlx_data *data, char *map_path)
{
	data->map.map_path = map_path;
	init_fc(data);
	init_wall_txt(data);
	init_map(data);
	init_screen(data);
	init_img(data);
	init_txt(data);
	init_player(data);
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
}
