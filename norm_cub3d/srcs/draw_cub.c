/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:34:37 by soum              #+#    #+#             */
/*   Updated: 2022/06/10 23:02:56 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

mlx_texture_t	*find_wall_txt(t_point *pnt, t_texture *txt)
{
	if (pnt->is_door == 2)
		return (txt->door_txt);
	if (pnt->type == 'N')
		return (txt->n_wall_txt);
	else if (pnt->type == 'S')
		return (txt->s_wall_txt);
	else if (pnt->type == 'E')
		return (txt->e_wall_txt);
	else if (pnt->type == 'W')
		return (txt->w_wall_txt);
	return (NULL);
}

int	draw_txt_pos(t_point *ray, mlx_texture_t *txt, t_door *door)
{
	int	txt_pos;

	txt_pos = 0;
	if (ray->type == 'N' || ray->type == 'S')
	{
		txt_pos = (int)(ray->map_x) % GRID;
		if (ray->is_door == 2 && ray->wall_len <= GRID * 2)
			txt_pos = ((int)ray->map_x - (int)door->start_x) % GRID;
	}
	else if (ray->type == 'W' || ray->type == 'E')
	{
		txt_pos = (int)(ray->map_y) % GRID;
		if (ray->is_door == 2 && ray->wall_len <= GRID * 2)
			txt_pos = ((int)ray->map_y - (int)door->start_y) % GRID;
	}
	txt_pos = (txt->width * (double)txt_pos) / GRID;
	return (txt_pos);
}

void	draw_wall(t_point *pnt, t_mlx_data *data, int i)
{
	int				draw_pixel_y;
	int				txt_pos;
	double			start_end_xy[4];
	double			tmp_xy[2];
	mlx_texture_t	*txt;

	tmp_xy[0] = 0;
	txt = find_wall_txt(pnt, &data->texture);
	txt_pos = draw_txt_pos(pnt, txt, &data->map.door_ani);
	draw_pixel_y = (SCREEN_H * data->screen.zoom / pnt->wall_len);
	tmp_xy[1] = draw_pixel_y;
	if (draw_pixel_y >= SCREEN_H)
	{
		tmp_xy[0] = (draw_pixel_y - SCREEN_H) / 2.0;
		tmp_xy[0] = (tmp_xy[0] / draw_pixel_y) * txt->height;
		draw_pixel_y = SCREEN_H;
	}
	start_end_xy[0] = i * 2.0;
	start_end_xy[2] = (i * 2.0) + 2.0;
	start_end_xy[1] = (SCREEN_H - draw_pixel_y) / 2.0;
	start_end_xy[3] = start_end_xy[1] + draw_pixel_y;
	put_wall_pixel(data, start_end_xy, tmp_xy, txt_pos, txt);
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
			draw_wall(&data->pnt[(i + 1) % PNT_CNT], data, i);
		else
			draw_wall(&data->pnt[i], data, i);
		i++;
	}
}
