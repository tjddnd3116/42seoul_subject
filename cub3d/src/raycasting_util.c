/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:07:13 by soum              #+#    #+#             */
/*   Updated: 2022/09/04 15:07:13 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "door.h"

typedef int	(*t_special_type_func)(t_ray *ray, uint32_t *type, double angle);

static const
	t_special_type_func g_special_type_table[16] = {
	check_east_door,
	check_west_door,
	check_south_door,
	check_north_door
};

uint32_t	apply_fog_bswap(uint32_t color, double fog)
{
	unsigned char	bytes[4];
	uint32_t		ret;

	bytes[0] = (unsigned char)((color >> 24) & 0xff);
	bytes[1] = (unsigned char)((color >> 16) & 0xff);
	bytes[2] = (unsigned char)((color >> 8) & 0xff);
	bytes[3] = (unsigned char)((color >> 0) & 0xff);
	bytes[1] *= fog;
	bytes[2] *= fog;
	bytes[3] *= fog;
	ret = ((uint32_t)bytes[0] << 0) | \
		((uint32_t)bytes[1] << 8) | \
		((uint32_t)bytes[2] << 16) | \
		((uint32_t)bytes[3] << 24);
	return (ret);
}

uint32_t	apply_fog(uint32_t color, double fog)
{
	unsigned char	bytes[4];
	uint32_t		ret;

	bytes[0] = (unsigned char)((color >> 24) & 0xff);
	bytes[1] = (unsigned char)((color >> 16) & 0xff);
	bytes[2] = (unsigned char)((color >> 8) & 0xff);
	bytes[3] = (unsigned char)((color >> 0) & 0xff);
	bytes[0] *= fog;
	bytes[1] *= fog;
	bytes[2] *= fog;
	ret = ((uint32_t)bytes[0] << 24) | \
		((uint32_t)bytes[1] << 16) | \
		((uint32_t)bytes[2] << 8) | \
		((uint32_t)bytes[3] << 0);
	return (ret);
}

int	get_pos(mlx_texture_t *texture, t_ray *point, uint32_t type)
{
	int	pos;

	pos = (lround(point->x) + lround(point->y)) % GRID_LEN;
	if (point->direction == DOOR)
	{
		if ((lround(point->x) % HALF_GRID_LEN) == 0)
		{
			if (type < GRID_LEN)
				pos = lround(point->y) % GRID_LEN - type;
			else
				pos = lround(point->y) % GRID_LEN + (type % GRID_LEN);
		}
		else
		{
			if (type < GRID_LEN)
				pos = lround(point->x) % GRID_LEN - type;
			else
				pos = lround(point->x) % GRID_LEN + (type % GRID_LEN);
		}
	}
	pos = texture->width * pos / GRID_LEN;
	return (pos);
}

int	map_type_check(t_ray *ray, t_map *map, double angle)
{
	int			table_idx;
	uint32_t	*type;

	type = &map->map[lround(ray->y) / GRID_LEN][lround(ray->x) / GRID_LEN];
	if ((*type & (SPECIAL_TYPE_BITMASK | TYPE_BITMASK)) == MAP_EMPTY)
		return (1);
	else if ((*type & (SPECIAL_TYPE_BITMASK | TYPE_BITMASK))
		== MAP_SPRITE_NONBLOCK)
		return (1);
	else if ((*type & (SPECIAL_TYPE_BITMASK | TYPE_BITMASK)) == MAP_WALL)
		return (0);
	table_idx = (*type & SPECIAL_TYPE_BITMASK)
		- TYPE_BITMASK - 1 + ray->direction;
	return (g_special_type_table[table_idx](ray, type, angle));
}
