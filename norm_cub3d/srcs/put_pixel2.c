/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:23:42 by soum              #+#    #+#             */
/*   Updated: 2022/06/06 01:08:22 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <math.h>

void	put_razer_pixel(t_mlx_data *data, mlx_image_t *bg_img)
{
	double	angle;
	t_point	player;
	int		i;

	player.x = data->player.scaled_mid_pos[0];
	player.y = data->player.scaled_mid_pos[1];
	player.color = 0xff0000ff;
	i = 0;
	while (i < PNT_CNT)
	{
		angle = data->pnt[0].angle;
		if (angle == 0.0 || angle == 90.0 || angle == 180.0 || angle == 270.0)
			fdf_drawline(bg_img, &data->pnt[(i + 1) % PNT_CNT], &player);
		else
			fdf_drawline(bg_img, &data->pnt[i], &player);
		i++;
	}
}
