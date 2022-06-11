/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:32:32 by soum              #+#    #+#             */
/*   Updated: 2022/06/11 20:07:50 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	copy_ray_data(t_point *pnt, t_ray *ray)
{
	pnt->map_x = ray->xy[0];
	pnt->map_y = ray->xy[1];
	pnt->wall_len = ray->wall_len;
	pnt->type = ray->type;
	pnt->is_close_door = ray->is_close_door;
	pnt->is_open_door = ray->is_open_door;
	pnt->open_door_grid[0] = ray->open_door_grid[0];
	pnt->open_door_grid[1] = ray->open_door_grid[1];
	pnt->open_door_len = ray->open_door_len;
}

void	init_ray_data(t_ray *ray, t_mlx_data *data)
{
	ray->origin_xy[0] = data->player.mid_pos[0];
	ray->origin_xy[1] = data->player.mid_pos[1];
	ray->is_close_door = 0;
	ray->is_open_door = 0;
	ray->open_door_grid[0] = 0;
	ray->open_door_grid[1] = 0;
	ray->open_door_len = 0;
}
