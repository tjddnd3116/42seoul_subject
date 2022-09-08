/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:06:28 by soum              #+#    #+#             */
/*   Updated: 2022/09/07 17:36:54 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door.h"

int	check_east_door(t_ray *ray, uint32_t *type, double angle)
{
	int32_t	map_pos;
	t_ray	temp;

	temp = *ray;
	map_pos = *type >> INFO_BITSHIFT;
	ray->x -= GRID_LEN / 2.0;
	ray->y += -GRID_LEN / 2.0 * -1 / tan(angle);
	if (map_pos > GRID_LEN)
		map_pos = 2 * GRID_LEN - map_pos;
	map_pos -= lround(ray->y) % GRID_LEN;
	if (map_pos > 0)
	{
		*ray = temp;
		return (1);
	}
	ray->direction = DOOR;
	return (0);
}

int	check_west_door(t_ray *ray, uint32_t *type, double angle)
{
	int32_t	map_pos;
	t_ray	temp;

	temp = *ray;
	map_pos = *type >> INFO_BITSHIFT;
	ray->x += GRID_LEN / 2.0;
	ray->y += -GRID_LEN / 2.0 / tan(angle);
	if (map_pos > GRID_LEN)
		map_pos = 2 * GRID_LEN - map_pos;
	map_pos -= lround(ray->y) % GRID_LEN;
	if (map_pos > 0)
	{
		*ray = temp;
		return (1);
	}
	ray->direction = DOOR;
	return (0);
}

int	check_south_door(t_ray *ray, uint32_t *type, double angle)
{
	int32_t	map_pos;
	t_ray	temp;

	temp = *ray;
	map_pos = *type >> INFO_BITSHIFT;
	ray->y += GRID_LEN / 2.0;
	ray->x += -GRID_LEN / 2.0 * tan(angle);
	if (map_pos > GRID_LEN)
		map_pos = 2 * GRID_LEN - map_pos;
	map_pos -= lround(ray->x) % GRID_LEN;
	if (map_pos > 0)
	{
		*ray = temp;
		return (1);
	}
	ray->direction = DOOR;
	return (0);
}

int	check_north_door(t_ray *ray, uint32_t *type, double angle)
{
	int32_t	map_pos;
	t_ray	temp;

	temp = *ray;
	map_pos = *type >> INFO_BITSHIFT;
	ray->y -= GRID_LEN / 2.0;
	ray->x += -GRID_LEN / 2.0 * -1 * tan(angle);
	if (map_pos > GRID_LEN)
		map_pos = 2 * GRID_LEN - map_pos;
	map_pos -= lround(ray->x) % GRID_LEN;
	if (map_pos > 0)
	{
		*ray = temp;
		return (1);
	}
	ray->direction = DOOR;
	return (0);
}

uint32_t	*door_event(t_mlx_data *data)
{
	uint32_t	map_pos;
	uint32_t	*type;
	t_ray		mid_point;

	if ((data->map.map[data->player.grid.y][data->player.grid.x]
		& SPECIAL_TYPE_BITMASK) == MAP_DOOR_OPENED)
		return (NULL);
	mid_point = detect_door(data->player, data->map);
	if (mid_point.direction != DOOR || mid_point.distance >= g_door_distance)
		return (NULL);
	type = &data->map.map[lround(mid_point.y) / GRID_LEN]
	[lround(mid_point.x) / GRID_LEN];
	map_pos = *type >> INFO_BITSHIFT;
	if (map_pos == 2 * GRID_LEN)
	{
		*type &= ~INFO_BITMASK;
		map_pos = 0;
	}
	if (map_pos == 0 || map_pos == 512)
		*type += DOOR_DIFF << INFO_BITSHIFT;
	if (map_pos == 512)
		*type ^= 1;
	return (type);
}
