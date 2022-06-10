/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_wall2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:51:45 by soum              #+#    #+#             */
/*   Updated: 2022/06/10 22:50:44 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	find_y_txt(t_ray *pnt, t_map *map_data, double angle, int *grid_xy)
{
	int	ret;

	ret = 0;
	if (map_data->map[grid_xy[1]][grid_xy[0]] == '1')
		ret = 1;
	else if (map_data->map[grid_xy[1]][grid_xy[0]] == '2')
		pnt->is_door = 1;
	else if (map_data->map[grid_xy[1]][grid_xy[0]] == '3')
	{
		if (angle < 90 || angle > 270)
			pnt->xy[1] -= GRID / 2.0;
		else if (angle > 90 && angle < 270)
			pnt->xy[1] += GRID / 2.0;
		pnt->xy[0] = pnt->origin_xy[0] + ((pnt->origin_xy[1] \
					- pnt->xy[1]) * tan(angle * (M_PI / 180)));
		pnt->wall_len = sqrt(pow(pnt->origin_xy[0] - pnt->xy[0], 2.0) + \
				pow(pnt->origin_xy[1] - pnt->xy[1], 2.0));
		if (!check_door_action(pnt, map_data))
			return (ret);
		ret = 2;
		/** pnt->is_door += 1; */
	}
	return (ret);
}

int	find_x_txt(t_ray *pnt, t_map *map_data, double angle, int *grid_xy)
{
	int	ret;

	ret = 0;
	if (map_data->map[grid_xy[1]][grid_xy[0]] == '1')
		ret = 1;
	else if (map_data->map[grid_xy[1]][grid_xy[0]] == '2')
		pnt->is_door = 1;
	else if (map_data->map[grid_xy[1]][grid_xy[0]] == '3')
	{
		if (angle < 180)
			pnt->xy[0] += GRID / 2.0;
		else if (angle > 180)
			pnt->xy[0] -= GRID / 2.0;
		pnt->xy[1] = pnt->origin_xy[1] + ((pnt->origin_xy[0] \
					- pnt->xy[0]) / tan(angle * (M_PI / 180)));
		pnt->wall_len = sqrt(pow(pnt->origin_xy[0] - pnt->xy[0], 2.0) + \
				pow(pnt->origin_xy[1] - pnt->xy[1], 2.0));
		if (!check_door_action(pnt, map_data))
			return (ret);
		ret = 2;
		/** pnt->is_door += 1; */
	}
	return (ret);
}
