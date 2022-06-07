/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:59:42 by soum              #+#    #+#             */
/*   Updated: 2022/06/06 14:43:33 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <math.h>

void	set_fov_pos(t_mlx_data *data)
{
	int			start_angle;
	int			i;
	t_player	*player;

	player = &data->player;
	start_angle = (360 + (data->player.angle - 30)) % 360;
	i = -1;
	while (++i < PNT_CNT)
	{
		data->pnt[i].angle = start_angle + (i * 0.083);
		if (data->pnt[i].angle >= 360.0)
			data->pnt[i].angle -= 360.0;
		data->pnt[i].degree = data->pnt[i].angle * (M_PI / 180);
		data->pnt[i].color = RED;
		detect_wall(data, &data->pnt[i]);
		data->pnt[i].x = scale_map_to_scn_single(data->pnt[i].map_x, \
				data->map->width, SCREEN_W);
		data->pnt[i].y = scale_map_to_scn_single(data->pnt[i].map_y, \
				data->map->height, SCREEN_H);
		data->pnt[i].wall_len = sqrt(pow(player->scaled_mid_pos[0] - \
					data->pnt[i].x, 2.0) + \
				pow(player->scaled_mid_pos[1] - data->pnt[i].y, 2.0));
		data->pnt[i].wall_len = data->pnt[i].wall_len * cos((player->angle - \
					data->pnt[i].angle) * (M_PI / 180));
	}
}
