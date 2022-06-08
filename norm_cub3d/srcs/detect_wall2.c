/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_wall2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:51:45 by soum              #+#    #+#             */
/*   Updated: 2022/06/08 22:59:57 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <math.h>

int	find_y_txt(t_ray *pnt, t_map *map_data, double angle, int *grid_xy)
{
	int	ret;

	ret = 0;
	pnt->type = 'N';
	pnt->is_door = 0;
	if (angle > 90 && angle < 270)
		pnt->type = 'S';
	if (map_data->map[grid_xy[1]][grid_xy[0]] == '1')
		ret = 1;
	if (map_data->map[grid_xy[1]][grid_xy[0]] == '2')
	{
		ret = 2;
		pnt->is_door = 1;
		if (angle < 90 || angle > 270)
			pnt->xy[1] -= GRID / 2.0;
		else if (angle > 90 && angle < 270)
			pnt->xy[1] += GRID / 2.0;
		pnt->xy[0] = pnt->origin_xy[0] + ((pnt->origin_xy[1] \
					- pnt->xy[1]) * tan(angle * (M_PI / 180)));
		pnt->wall_len = sqrt(pow(pnt->origin_xy[0] - pnt->xy[0], 2.0) + \
				pow(pnt->origin_xy[1] - pnt->xy[1], 2.0));
	}
	return (ret);
}

int	find_x_txt(t_ray *pnt, t_map *map_data, double angle, int *grid_xy)
{
	int	ret;

	ret = 0;
	pnt->type = 'E';
	pnt->is_door = 0;
	if (angle > 180)
		pnt->type = 'W';
	if (map_data->map[grid_xy[1]][grid_xy[0]] == '1')
		ret = 1;
	else if (map_data->map[grid_xy[1]][grid_xy[0]] == '2')
	{
		ret = 2;
		pnt->is_door = 1;
		if (angle < 180)
			pnt->xy[0] += GRID / 2.0;
		else if (angle > 180)
			pnt->xy[0] -= GRID / 2.0;
		pnt->xy[1] = pnt->origin_xy[1] + ((pnt->origin_xy[0] \
					- pnt->xy[0]) / tan(angle * (M_PI / 180)));
		pnt->wall_len = sqrt(pow(pnt->origin_xy[0] - pnt->xy[0], 2.0) + \
				pow(pnt->origin_xy[1] - pnt->xy[1], 2.0));
	}
	return (ret);
}
