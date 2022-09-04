/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:06:37 by soum              #+#    #+#             */
/*   Updated: 2022/09/04 15:06:37 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "cub3d.h"
#include "sprite.h"
#include "raycasting.h"

t_ray		detect_enemy(t_camera camera, t_map map);
static int	enemy_check(t_ray *ray, t_map *map);
t_ray		detect_x_enemy(t_camera camera, t_map map);
t_ray		detect_y_enemy(t_camera camera, t_map map);

void	enemy_got_shot(t_mlx_data *mlx_data)
{
	t_map		*map;
	t_camera	camera;
	t_ray		mid_point;

	camera = mlx_data->player;
	map = &mlx_data->map;
	mid_point = detect_enemy(camera, *map);
	if (mid_point.direction == ENEMY)
	{
		*(map->map[lround(mid_point.y) / GRID_LEN]
				+ lround(mid_point.x) / GRID_LEN)
			= MAP_EMPTY;
	}
}

t_ray	detect_enemy(t_camera camera, t_map map)
{
	t_ray	x_point;
	t_ray	y_point;

	if (camera.angle < 0.0)
		camera.angle += 2.0 * M_PI;
	else if (camera.angle >= 2.0 * M_PI)
		camera.angle -= 2.0 * M_PI;
	y_point = detect_y_enemy(camera, map);
	x_point = detect_x_enemy(camera, map);
	if (x_point.distance <= y_point.distance)
		return (x_point);
	return (y_point);
}

t_ray	detect_x_enemy(t_camera camera, t_map map)
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
	while (boundary_check(ray, map) && enemy_check(&ray, &map))
	{
		ray.x += GRID_LEN * direction_flag;
		ray.y += dy;
	}
	ray.distance = get_distance(ray, camera)
		+ !boundary_check(ray, map) * INT32_MAX;
	return (ray);
}

t_ray	detect_y_enemy(t_camera camera, t_map map)
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
	while (boundary_check(ray, map) && enemy_check(&ray, &map))
	{
		ray.y += GRID_LEN * direction_flag;
		ray.x += dx;
	}
	ray.distance = get_distance(ray, camera)
		+ !boundary_check(ray, map) * INT32_MAX;
	return (ray);
}

static int	enemy_check(t_ray *ray, t_map *map)
{
	uint32_t	*type;

	type = &map->map[lround(ray->y) / GRID_LEN][lround(ray->x) / GRID_LEN];
	if ((*type & (SPECIAL_TYPE_BITMASK | TYPE_BITMASK)) == MAP_WALL)
		return (0);
	if ((*type & (SPECIAL_TYPE_BITMASK | TYPE_BITMASK)) == MAP_SPRITE_NONBLOCK
		&& (*type >> INFO_BITSHIFT == 4))
	{
		ray->direction = ENEMY;
		return (0);
	}
	return (1);
}
