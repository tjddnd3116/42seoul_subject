/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:06:31 by soum              #+#    #+#             */
/*   Updated: 2022/09/04 15:06:31 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door.h"

static t_ray	detect_x_door(t_camera camera, t_map map);
static t_ray	detect_y_door(t_camera camera, t_map map);
static int		door_check(t_ray *ray, t_map *map);

t_ray	detect_door(t_camera camera, t_map map)
{
	t_ray	x_point;
	t_ray	y_point;

	if (camera.angle < 0.0)
		camera.angle += 2.0 * M_PI;
	else if (camera.angle >= 2.0 * M_PI)
		camera.angle -= 2.0 * M_PI;
	y_point = detect_y_door(camera, map);
	x_point = detect_x_door(camera, map);
	if (x_point.distance <= y_point.distance)
		return (x_point);
	return (y_point);
}

t_ray	detect_x_door(t_camera camera, t_map map)
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
	while (boundary_check(ray, map) && door_check(&ray, &map))
	{
		ray.x += GRID_LEN * direction_flag;
		ray.y += dy;
	}
	ray.distance = get_distance(ray, camera)
		+ !boundary_check(ray, map) * INT32_MAX;
	return (ray);
}

t_ray	detect_y_door(t_camera camera, t_map map)
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
	while (boundary_check(ray, map) && door_check(&ray, &map))
	{
		ray.y += GRID_LEN * direction_flag;
		ray.x += dx;
	}
	ray.distance = get_distance(ray, camera)
		+ !boundary_check(ray, map) * INT32_MAX;
	return (ray);
}

static int	door_check(t_ray *ray, t_map *map)
{
	uint32_t	*type;

	type = &map->map[lround(ray->y) / GRID_LEN][lround(ray->x) / GRID_LEN];
	if ((*type & (SPECIAL_TYPE_BITMASK | TYPE_BITMASK)) == MAP_WALL)
		return (0);
	if ((*type & (SPECIAL_TYPE_BITMASK | TYPE_BITMASK)) == MAP_DOOR_CLOSED
		|| (*type & (SPECIAL_TYPE_BITMASK | TYPE_BITMASK)) == MAP_DOOR_OPENED)
	{
		ray->direction = DOOR;
		return (0);
	}
	return (1);
}
