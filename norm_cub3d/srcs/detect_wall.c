/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:59:06 by soum              #+#    #+#             */
/*   Updated: 2022/06/03 21:58:10 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_wall(double *x_pos, double *y_pos, char **map, t_mlx_data *data)
{
	int	grid_x;
	int	grid_y;

	if (*x_pos < 0)
		*x_pos = 0;
	else if (*x_pos >= GRID * data->map->cub_x)
		*x_pos = GRID * data->map->cub_x - 1;
	if (*y_pos < 0)
		*y_pos = 0;
	else if (*y_pos >= GRID * data->map->cub_y)
		*y_pos = GRID * data->map->cub_y - 1;
	grid_x = *x_pos / GRID;
	grid_y = *y_pos / GRID;
	if (map[grid_y][grid_x] == '1')
		return (1);
	return (0);
}

void	detect_x_wall(t_point *pnt, t_mlx_data *data, \
		double angle, double degree)
{
	int32_t	ray_x;
	int32_t	ray_y;
	int		grid_x;

	ray_x = data->player.mid_pos[0];
	ray_y = data->player.mid_pos[1];
	grid_x = ray_x / GRID;
	while (grid_x >= 0 && grid_x < data->map->width)
	{
		if (angle < 180)
			pnt->x = grid_x * GRID + GRID;
		else
			pnt->x = grid_x * GRID - 1;
		if (angle == 180.0 || angle == 0.0)
			pnt->y = ray_y;
		else
			pnt->y = ray_y + (ray_x - pnt->x) / tan(degree);
		pnt->wall_len = sqrt(pow(pnt->x - ray_x, 2.0) + \
				pow(pnt->y - ray_y, 2.0));
		if (is_wall(&pnt->x, &pnt->y, data->map->map, data))
			return ;
		grid_x--;
		if (angle < 180)
			grid_x += 2;
	}
}

void	detect_y_wall(t_point *pnt, t_mlx_data *data, \
		double angle, double degree)
{
	int32_t	ray_x;
	int32_t	ray_y;
	int		grid_y;

	ray_x = data->player.mid_pos[0];
	ray_y = data->player.mid_pos[1];
	grid_y = ray_y / GRID;
	while (grid_y >= 0 && grid_y < data->map->height)
	{
		if (angle < 90 || 270 < angle)
			pnt->y = grid_y * GRID - 1;
		else
			pnt->y = grid_y * GRID + GRID;
		if (angle == 90.0 || angle == 270.0)
			pnt->x = ray_x;
		else
			pnt->x = ray_x + (ray_y - pnt->y) * tan(degree);
		pnt->wall_len = sqrt(pow(pnt->x - ray_x, 2.0) + \
				pow(pnt->y - ray_y, 2.0));
		if (is_wall(&pnt->x, &pnt->y, data->map->map, data))
			return ;
		grid_y++;
		if (angle < 90 || angle > 270)
			grid_y -= 2;
	}
}

void	detect_wall(t_mlx_data *data, t_point *pnt)
{
	t_point	tmp_y;
	t_point	tmp_x;

	detect_y_wall(&tmp_y, data, pnt->angle, pnt->degree);
	detect_x_wall(&tmp_x, data, pnt->angle, pnt->degree);
	if (tmp_y.wall_len < tmp_x.wall_len)
	{
		pnt->map_x = tmp_y.x;
		pnt->map_y = tmp_y.y;
		/** [> [> [> pnt->wall_len = tmp_y.wall_len * cos((data->player.angle - \ <] <] <] */
		/** [> [>             [> pnt->angle) * M_PI / 180); <] <] <] */
		/** pnt->wall_len = tmp_y.wall_len; */
		pnt->grid_x = pnt->map_x / GRID;
		pnt->grid_y = pnt->map_y / GRID;
	}
	else
	{
		pnt->map_x = tmp_x.x;
		pnt->map_y = tmp_x.y;
		/** [> [> pnt->wall_len = tmp_x.wall_len * cos((data->player.angle - \ <] <] */
		/** [> [>              pnt->angle) * M_PI / 180); <] <] */
		/** pnt->wall_len = tmp_x.wall_len; */
		pnt->grid_x = pnt->map_x / GRID;
		pnt->grid_y = pnt->map_y / GRID;
	}
}
