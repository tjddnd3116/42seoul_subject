/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 20:40:02 by soum              #+#    #+#             */
/*   Updated: 2022/06/11 20:11:26 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	pnt_scale(t_mlx_data *data, int i)
{
		data->pnt[i].x = scale_map_to_scn_single(data->pnt[i].map_x, \
				data->map.width, MINIMAP_W);
		data->pnt[i].y = scale_map_to_scn_single(data->pnt[i].map_y, \
				data->map.height, MINIMAP_H);
		data->pnt[i].wall_len = data->pnt[i].wall_len * \
				cos((data->player.angle - \
				data->pnt[i].angle) * (M_PI / 180));
}

inline int	scale_map_to_scn_single(int val, int map_size, int scn_size)
{
	int	result;

	result = ((double)val * scn_size) / map_size;
	return (result);
}

void	scale_map_to_scn(int *pos, int *scaled_pos, t_map *map_data)
{
	double	x_pos;
	double	y_pos;
	int		width;
	int		height;

	x_pos = pos[0];
	y_pos = pos[1];
	width = map_data->width;
	height = map_data->height;
	scaled_pos[0] = (x_pos / width) * MINIMAP_W;
	scaled_pos[1] = (y_pos / height) * MINIMAP_H;
}

void	scale_scn_to_map(int *pos, int *scaled_pos, t_map *map_data)
{
	double	x_pos;
	double	y_pos;
	int		width;
	int		height;

	x_pos = pos[0];
	y_pos = pos[1];
	width = map_data->width;
	height = map_data->height;
	scaled_pos[0] = (x_pos / MINIMAP_W) * width;
	scaled_pos[1] = (y_pos / MINIMAP_H) * height;
}
