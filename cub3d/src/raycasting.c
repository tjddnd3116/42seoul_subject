/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:07:10 by soum              #+#    #+#             */
/*   Updated: 2022/09/04 15:07:10 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static t_ray	detect_x_wall(t_camera camera, t_map map);
static t_ray	detect_y_wall(t_camera camera, t_map map);

t_ray	detect_wall(t_camera camera, t_map map)
{
	t_ray	x_point;
	t_ray	y_point;

	if (camera.angle < 0.0)
		camera.angle += 2.0 * M_PI;
	else if (camera.angle >= 2.0 * M_PI)
		camera.angle -= 2.0 * M_PI;
	y_point = detect_y_wall(camera, map);
	x_point = detect_x_wall(camera, map);
	if (x_point.distance <= y_point.distance)
		return (x_point);
	return (y_point);
}

t_ray	detect_x_wall(t_camera camera, t_map map)
{
	t_ray	ray;
	double	dy;
	int		direction_flag;

	direction_flag = 1;
	ray.x = (camera.grid.x + 1) * GRID_LEN;
	ray.direction = WEST;
	if (camera.angle >= M_PI)
	{
		direction_flag = -1;
		ray.x = camera.grid.x * GRID_LEN - 1;
		ray.direction = EAST;
	}
	ray.y = camera.y
		- (ray.x - 0.5 * direction_flag - camera.x) / tan(camera.angle);
	dy = -GRID_LEN * direction_flag / tan(camera.angle);
	while (boundary_check(ray, map) && map_type_check(&ray, &map, camera.angle))
	{
		ray.x += GRID_LEN * direction_flag;
		ray.y += dy;
	}
	ray.distance = get_distance(ray, camera)
		+ !boundary_check(ray, map) * INT32_MAX;
	ray.x += (direction_flag == -1);
	return (ray);
}

t_ray	detect_y_wall(t_camera camera, t_map map)
{
	t_ray	ray;
	double	dx;
	int		direction_flag;

	direction_flag = 1;
	ray.y = (camera.grid.y + 1) * GRID_LEN;
	ray.direction = SOUTH;
	if (camera.angle <= M_PI_2 || camera.angle >= M_PI_2 * 3)
	{
		direction_flag = -1;
		ray.y = camera.grid.y * GRID_LEN - 1;
		ray.direction = NORTH;
	}
	ray.x = camera.x
		- (ray.y - 0.5 * direction_flag - camera.y) * tan(camera.angle);
	dx = -GRID_LEN * direction_flag * tan(camera.angle);
	while (boundary_check(ray, map) && map_type_check(&ray, &map, camera.angle))
	{
		ray.y += GRID_LEN * direction_flag;
		ray.x += dx;
	}
	ray.distance = get_distance(ray, camera)
		+ !boundary_check(ray, map) * INT32_MAX;
	ray.y += (direction_flag == -1);
	return (ray);
}

double	get_distance(t_ray ray, t_camera camera)
{
	return (sqrt(pow(ray.x - camera.x, 2.0) + pow(ray.y - camera.y, 2.0)));
}

int	boundary_check(t_ray ray, t_map map)
{
	if (ray.x >= 0 && lround(ray.x) < GRID_LEN * map.width
		&& ray.y >= 0 && lround(ray.y) < GRID_LEN * map.height)
		return (1);
	return (0);
}
