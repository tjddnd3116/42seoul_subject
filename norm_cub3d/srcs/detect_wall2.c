/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_wall2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:51:45 by soum              #+#    #+#             */
/*   Updated: 2022/06/11 21:07:41 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	open_door_txt(t_ray *pnt, int *grid_xy)
{
	if (pnt->is_open_door || pnt->wall_len > GRID)
		return ;
	pnt->is_open_door = 1;
	pnt->open_door_grid[0] = grid_xy[0];
	pnt->open_door_grid[1] = grid_xy[1];
	pnt->open_door_len = pnt->wall_len;
}

void	close_door_txt(t_ray *pnt, double angle)
{
	if (pnt->type == 'N')
		pnt->xy[1] -= GRID / 2.0;
	else if (pnt->type == 'S')
		pnt->xy[1] += GRID / 2.0;
	else if (pnt->type == 'E')
		pnt->xy[0] += GRID / 2.0;
	else if (pnt->type == 'W')
		pnt->xy[0] -= GRID / 2.0;
	if (pnt->type == 'N' || pnt->type == 'S')
		pnt->xy[0] = pnt->origin_xy[0] + ((pnt->origin_xy[1] \
					- pnt->xy[1]) * tan(angle * (M_PI / 180)));
	else if (pnt->type == 'E' || pnt->type == 'W')
		pnt->xy[1] = pnt->origin_xy[1] + ((pnt->origin_xy[0] \
					- pnt->xy[0]) / tan(angle * (M_PI / 180)));
	pnt->wall_len = sqrt(pow(pnt->origin_xy[0] - pnt->xy[0], 2.0) + \
			pow(pnt->origin_xy[1] - pnt->xy[1], 2.0));
}

int	find_y_txt(t_ray *pnt, t_map *map_data, double angle, int *grid_xy)
{
	int	ret;

	ret = 0;
	if (map_data->map[grid_xy[1]][grid_xy[0]] == '1')
		ret = 1;
	else if (map_data->map[grid_xy[1]][grid_xy[0]] == '2')
	{
		close_door_txt(pnt, angle);
		open_door_txt(pnt, grid_xy);
	}
	else if (map_data->map[grid_xy[1]][grid_xy[0]] == '3')
	{
		close_door_txt(pnt, angle);
		if (!check_door_action(pnt, map_data))
			return (ret);
		ret = 2;
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
		open_door_txt(pnt, grid_xy);
	else if (map_data->map[grid_xy[1]][grid_xy[0]] == '3')
	{
		close_door_txt(pnt, angle);
		if (!check_door_action(pnt, map_data))
			return (ret);
		ret = 2;
	}
	return (ret);
}
