/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InitPlayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:09:37 by soum              #+#    #+#             */
/*   Updated: 2022/06/12 19:21:10 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	player_pos_scale(t_player *p, t_map *map_data)
{
	int	x_pos;
	int	y_pos;

	x_pos = p->pos[0];
	y_pos = p->pos[1];
	p->mid_pos[0] = x_pos + (PLAYER_SIZE / 2);
	p->mid_pos[1] = y_pos + (PLAYER_SIZE / 2);
	pos_togrid(p->mid_pos, p->grid);
	scale_map_to_scn(p->pos, p->scaled_pos, map_data);
	scale_map_to_scn(p->mid_pos, p->scaled_mid_pos, map_data);
	p->scale_size[0] = (PLAYER_SIZE * MINIMAP_W) / map_data->width;
	p->scale_size[1] = (PLAYER_SIZE * MINIMAP_H) / map_data->height;
}

void	player_angle(t_mlx_data *data, t_player *p, char direction)
{
	if (direction == 'N')
		p->angle = 0;
	else if (direction == 'E')
		p->angle = 90;
	else if (direction == 'S')
		p->angle = 180;
	else if (direction == 'W')
		p->angle = 270;
	else
		error_msg("check cub file (player angle)", PLAYER_INIT_ERR, data);
}

void	find_player(t_mlx_data *data, t_player *p, t_map *map_data, char **map)
{
	int		x;
	int		y;
	int		player_cnt;

	player_cnt = 0;
	y = -1;
	while (++y < map_data->cub_y)
	{
		x = -1;
		while (++x < map_data->cub_x)
		{
			if (map[y][x] >= 65)
			{
				player_cnt++;
				player_angle(data, p, map[y][x]);
				p->pos[0] = GRID * x + (GRID / 2) - (PLAYER_SIZE / 2);
				p->pos[1] = GRID * y + (GRID / 2) - (PLAYER_SIZE / 2);
				player_pos_scale(p, map_data);
				map[y][x] = '0';
			}
		}
	}
	if (player_cnt != 1)
		error_msg("check cub file (number of player)", PLAYER_INIT_ERR, data);
}

int	init_player(t_mlx_data *data)
{
	t_player	*player;

	player = &data->player;
	player->size = PLAYER_SIZE;
	player->near_door = 0;
	find_player(data, player, &data->map, data->map.map);
	return (0);
}
