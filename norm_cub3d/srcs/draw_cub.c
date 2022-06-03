/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:34:37 by soum              #+#    #+#             */
/*   Updated: 2022/06/03 21:59:21 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	draw_wall_pos(t_point *ray, t_mlx_data *data)
{
	int	wall_pos;

	wall_pos = (int)ray->map_x % GRID;
	wall_pos += (int)ray->map_y % GRID;
	wall_pos = data->texture.wall_txt->width * (double)wall_pos / GRID;
	return (wall_pos);
}

void	draw_wall(mlx_image_t *cub_img, t_point *pnt, t_mlx_data *data)
{
	mlx_texture_t	*wall;
	int				start_y;
	int				end_y;
	double			start_x;
	double			end_x;
	int				wall_pos;
	double			tmp;
	int				tmp2;

	tmp = 0;
	wall = data->texture.wall_txt;
	wall_pos = draw_wall_pos(pnt, data);
	/** draw_pixel_y = (zoom * SCREEN_H / ) */
}

void	draw_cub(t_mlx_data *data)
{
	double	angle;
	int		i;

	i = 0;
	while (i < 300)
	{
		angle = data->pnt[i].angle;
		if (!fmod(angle, 90.0))
			draw_wall(data->image.cub_img, &data->pnt[(i + 1) % 300], data);
		else
			draw_wall(data->image.cub_img, &data->pnt[i], data);
		i++;
	}
}
