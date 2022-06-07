/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:23:42 by soum              #+#    #+#             */
/*   Updated: 2022/06/07 23:16:43 by soum             ###   ########.fr       */
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
			fdf_drawline(bg_img, &data->pnt[(i + 2) % PNT_CNT], &player);
		else
			fdf_drawline(bg_img, &data->pnt[i], &player);
		i++;
	}
}

void	put_wall_pixel(t_mlx_data *data, double *start_end_xy, \
		double *tmp_xy, int txt_pos, mlx_texture_t *wall_txt)
{
	double			p_y;
	uint32_t		color;
	int				start_y;

	while (start_end_xy[0] < start_end_xy[2])
	{
		p_y = tmp_xy[0];
		start_y = start_end_xy[1];
		while (start_y < start_end_xy[3])
		{
			p_y += (wall_txt->height - 1) / tmp_xy[1];
			if (p_y >= wall_txt->height)
				p_y = wall_txt->height - 1;
			color = *((uint32_t *)wall_txt->pixels + \
					((int)p_y * wall_txt->width + txt_pos));
			color = to_le(color);
			mlx_put_pixel(data->image.cub_img, start_end_xy[0], start_y, color);
			start_y++;
		}
		start_end_xy[0]++;
	}
}
