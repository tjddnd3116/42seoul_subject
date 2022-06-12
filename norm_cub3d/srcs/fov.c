/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:59:42 by soum              #+#    #+#             */
/*   Updated: 2022/06/11 20:09:12 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_fov_pos(t_mlx_data *data)
{
	int			start_angle;
	int			i;
	t_player	*player;
	double		angle_per_pnt;

	angle_per_pnt = (double)FOV / PNT_CNT;
	player = &data->player;
	start_angle = (360 + (data->player.angle - 30)) % 360;
	i = -1;
	while (++i < PNT_CNT)
	{
		data->pnt[i].angle = start_angle + (i * angle_per_pnt);
		if (data->pnt[i].angle >= 360.0)
			data->pnt[i].angle -= 360.0;
		data->pnt[i].degree = data->pnt[i].angle * (M_PI / 180);
		data->pnt[i].color = RED;
		detect_wall(data, &data->pnt[i]);
		pnt_scale(data, i);
	}
	data->player.near_door = is_near_door(data->pnt);
}
