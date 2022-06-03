/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:59:42 by soum              #+#    #+#             */
/*   Updated: 2022/06/03 21:58:21 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_fov_pos(t_mlx_data *data)
{
	int	start_angle;
	int	i;

	start_angle = (360 + (data->player.angle - 30)) % 360;
	i = 0;
	while (i < 300)
	{
		data->pnt[i].angle = start_angle + (i * 0.2);
		if (data->pnt[i].angle >= 360.0)
			data->pnt[i].angle -= 360.0;
		data->pnt[i].degree = data->pnt[i].angle * (M_PI / 180);
		data->pnt[i].color = 0xff0000ff;
		detect_wall(data, &data->pnt[i]);
		data->pnt[i].x = scale_map_to_scn_single(data->pnt[i].map_x, \
				data->map->width, SCREEN_W) + 1;
		data->pnt[i].y = scale_map_to_scn_single(data->pnt[i].map_y, \
				data->map->height, SCREEN_H) + 1;
		i++;
	}
}
