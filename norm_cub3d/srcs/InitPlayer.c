/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InitPlayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:09:37 by soum              #+#    #+#             */
/*   Updated: 2022/06/08 15:50:42 by soum             ###   ########.fr       */
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

void	player_angle(t_player *p, char direction)
{
	if (direction == 'N')
		p->angle = 0;
	else if (direction == 'E')
		p->angle = 90;
	else if (direction == 'S')
		p->angle = 180;
	else if (direction == 'W')
		p->angle = 270;
}

int	find_player(t_player *p, t_map *map_data, char **map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map_data->cub_y)
	{
		x = 0;
		while (x < map_data->cub_x)
		{
			if (map[y][x] == 'N' || map[y][x] == 'E' \
					|| map[y][x] == 'S' || map[y][x] == 'W')
			{
				p->pos[0] = GRID * x + (GRID / 2) - (PLAYER_SIZE / 2);
				p->pos[1] = GRID * y + (GRID / 2) - (PLAYER_SIZE / 2);
				player_pos_scale(p, map_data);
				player_angle(p, map[y][x]);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (PLAYER_ERROR);
}

int	init_player(t_mlx_data *data)
{
	t_player	*player;
	int			error_idx;

	player = &data->player;
	player->size = PLAYER_SIZE;
	player->near_door = 0;
	error_idx = find_player(player, &data->map, data->map.map);
	if (error_idx)
		return (error_idx);
	return (0);
}
