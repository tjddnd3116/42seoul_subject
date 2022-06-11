/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:59:06 by soum              #+#    #+#             */
/*   Updated: 2022/06/11 15:06:46 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_y_wall(t_ray *pnt, t_map *map_data, double angle)
{
	int	grid_xy[2];
	int	ret;

	pnt->type = 'S';
	if (angle < 90 || 270 < angle)
	{
		pnt->xy[1]--;
		pnt->type = 'N';
	}
	if (pnt->xy[0] >= GRID * map_data->cub_x)
		pnt->xy[0] = (GRID * map_data->cub_x) - GRID;
	if (pnt->xy[0] < 0)
		pnt->xy[0] = 0;
	grid_xy[0] = pnt->xy[0] / GRID;
	grid_xy[1] = pnt->xy[1] / GRID;
	if (angle < 90 || 270 < angle)
		pnt->xy[1]++;
	pnt->wall_len = sqrt(pow(pnt->origin_xy[0] - pnt->xy[0], 2.0) + \
			pow(pnt->origin_xy[1] - pnt->xy[1], 2.0));
	ret = find_y_txt(pnt, map_data, angle, grid_xy);
	return (ret);
}

int	is_x_wall(t_ray *pnt, t_map *map_data, double angle)
{
	int	grid_xy[2];
	int	ret;

	ret = 0;
	pnt->type = 'E';
	if (angle > 180)
	{
		pnt->xy[0]--;
		pnt->type = 'W';
	}
	if (pnt->xy[1] >= GRID * map_data->cub_y)
		pnt->xy[1] = GRID * map_data->cub_y - GRID;
	if (pnt->xy[1] < 0)
		pnt->xy[1] = 0;
	grid_xy[0] = pnt->xy[0] / GRID;
	grid_xy[1] = pnt->xy[1] / GRID;
	if (angle > 180)
		pnt->xy[0]++;
	pnt->wall_len = sqrt(pow(pnt->origin_xy[0] - pnt->xy[0], 2.0) + \
			pow(pnt->origin_xy[1] - pnt->xy[1], 2.0));
	ret = find_x_txt(pnt, map_data, angle, grid_xy);
	return (ret);
}

void	detect_y_wall(t_ray *pnt, t_mlx_data *data, \
		double angle, double degree)
{
	pnt->grid[1] = (pnt->origin_xy[1] - 1) / GRID;
	while (pnt->grid[1] >= 0 && pnt->grid[1] < data->map.height)
	{
		pnt->xy[1] = pnt->grid[1] * GRID;
		if (angle > 90 && angle < 270)
			pnt->xy[1] = pnt->grid[1] * GRID + GRID;
		if (angle == 90.0 || angle == 270.0)
		{
			pnt->wall_len = GRID * (data->map.cub_x * data->map.cub_y);
			return ;
		}
		else
			pnt->xy[0] = pnt->origin_xy[0] + ((pnt->origin_xy[1] \
						- pnt->xy[1]) * tan(degree));
		if (is_y_wall(pnt, &data->map, angle))
			return ;
		pnt->grid[1]++;
		if (angle < 90 || angle > 270)
			pnt->grid[1] -= 2;
	}
}

void	detect_x_wall(t_ray *pnt, t_mlx_data *data, \
		double angle, double degree)
{
	pnt->grid[0] = (pnt->origin_xy[0] - 1) / GRID;
	while (pnt->grid[0] >= 0 && pnt->grid[0] < data->map.width)
	{
		pnt->xy[0] = pnt->grid[0] * GRID;
		if (angle < 180)
			pnt->xy[0] = pnt->grid[0] * GRID + GRID;
		if (angle == 180.0 || angle == 0.0)
		{
			pnt->wall_len = GRID * (data->map.cub_x * data->map.cub_y);
			return ;
		}
		else
			pnt->xy[1] = pnt->origin_xy[1] + ((pnt->origin_xy[0] \
						- pnt->xy[0]) / tan(degree));
		if (is_x_wall(pnt, &data->map, angle))
			return ;
		if (angle < 180)
			pnt->grid[0]++;
		else
			pnt->grid[0]--;
	}
}

void	detect_wall(t_mlx_data *data, t_point *pnt)
{
	t_ray	tmp_y;
	t_ray	tmp_x;

	init_ray_data(&tmp_y, data);
	init_ray_data(&tmp_x, data);
	detect_y_wall(&tmp_y, data, pnt->angle, pnt->degree);
	detect_x_wall(&tmp_x, data, pnt->angle, pnt->degree);
	if (tmp_y.wall_len < tmp_x.wall_len)
		copy_ray_data(pnt, &tmp_y);
	else
		copy_ray_data(pnt, &tmp_x);
}
