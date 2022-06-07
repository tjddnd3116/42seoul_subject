/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:34:37 by soum              #+#    #+#             */
/*   Updated: 2022/06/06 14:49:25 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	draw_txt_pos(t_point *ray, t_mlx_data *data, mlx_texture_t *txt)
{
	int	txt_pos;
	(void)data;

	txt_pos = (int)(ray->map_x) % GRID;
	txt_pos += (int)(ray->map_y) % GRID;
	txt_pos = (txt->width * (double)txt_pos) / GRID;
	return (txt_pos);
}

void	draw_wall(mlx_image_t *cub_img, t_point *pnt, t_mlx_data *data, int i)
{
	mlx_texture_t	*txt;
	int				start_y;
	int				end_y;
	double			start_x;
	double			end_x;
	int				draw_pixel_y;
	int				txt_pos;
	double			tmp;
	int				tmp2;

	tmp = 0;
	txt = data->texture.wall_txt;
	/** if (pnt->type == '2') */
	/**     txt = data->texture.dice_txt; */
	txt_pos = draw_txt_pos(pnt, data, txt);
	draw_pixel_y = (SCREEN_H * data->screen.zoom / pnt->wall_len);
	tmp2 = draw_pixel_y;
	if (draw_pixel_y >= SCREEN_H)
	{
		tmp = (draw_pixel_y - SCREEN_H) / 2.0;
		tmp = (tmp / draw_pixel_y) * txt->height;
		draw_pixel_y = SCREEN_H;
	}
	start_y = (SCREEN_H - draw_pixel_y) / 2;
	end_y = start_y + draw_pixel_y;
	start_x = i * 3.5;
	end_x = (i * 3.5) + 3.5;
	for (double x = start_x; x < end_x; x++)
	{
		double p_y = tmp;
		for (int y = start_y; y < end_y; y++)
		{
			p_y += (txt->height - 1) / (double)tmp2;
			uint32_t color = *((uint32_t *)txt->pixels + ((int)p_y * txt->width + txt_pos));
			color = to_le(color);
			mlx_put_pixel(cub_img, x, y, color);
		}
	}

}

void	draw_cub(t_mlx_data *data)
{
	double	angle;
	int		i;

	i = 0;
	while (i < PNT_CNT)
	{
		angle = data->pnt[i].angle;
		if (angle == 0.0 || angle == 90.0 || angle == 180.0 || angle == 270.0)
			draw_wall(data->image.cub_img, &data->pnt[(i + 1) % PNT_CNT], data, i);
		else
			draw_wall(data->image.cub_img, &data->pnt[i], data, i);
		i++;
	}
}
