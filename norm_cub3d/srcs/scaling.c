/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 20:40:02 by soum              #+#    #+#             */
/*   Updated: 2022/06/03 21:05:21 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	scale_map_to_scn_single(int val, int map_size, int scn_size)
{
	int result;

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
	scaled_pos[0] = (x_pos / width) * SCREEN_W;
	scaled_pos[1] = (y_pos / height) * SCREEN_H;
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
	scaled_pos[0] = (x_pos / SCREEN_W) * width;
	scaled_pos[1] = (y_pos / SCREEN_H) * height;
}

