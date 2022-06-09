/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:23:42 by soum              #+#    #+#             */
/*   Updated: 2022/06/09 22:50:49 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <math.h>

void	put_minimap_dark(mlx_image_t *mini_img, t_player *player)
{
	int			*p_xy;
	uint32_t	x;
	uint32_t	y;
	double		len;

	p_xy = player->scaled_mid_pos;
	y = 0;
	while (y < mini_img->height)
	{
		x = 0;
		while (x < mini_img->width)
		{
			len = sqrt(pow(p_xy[0] - (int)x, 2.0) + pow(p_xy[1] - (int)y, 2.0));
			if (len >= 90.0)
				mlx_put_pixel(mini_img, x, y, 0x000000ff);
			x++;
		}
		y++;
	}

}

void	put_razer_pixel(t_mlx_data *data, mlx_image_t *bg_img)
{
	/** double	angle; */
	t_point	player;
	int		i;

	player.x = data->player.scaled_mid_pos[0];
	player.y = data->player.scaled_mid_pos[1];
	player.color = RED;
	i = 0;
	while (i < PNT_CNT)
	{
		/** angle = data->pnt[i].angle; */
		/** if ((int)angle == 0 || (int)angle == 90 || angle == 180.0 || angle == 270.0) */
		/**     fdf_drawline(bg_img, &data->pnt[(i + 1) % PNT_CNT], &player); */
		/** else */
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
