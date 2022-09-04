/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:06:25 by soum              #+#    #+#             */
/*   Updated: 2022/09/04 18:56:20 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

enum e_map_element
{
	CHECK_MAP_WALL = '1',
	CHECK_MAP_DOOR = '3',
	CHECK_MAP_EMPTY = '0',
	CHECK_MAP_CHECKED = 0b10000000
};

static int	check_closed(uint32_t **map, t_ivec2 pos, t_ivec2 *boundary);
static void	unmask_map(uint32_t **map, int rows, int cols);
static int	check_door(uint32_t **map, int rows, int cols,
				t_ivec2 *boundary);

/*
 * return value 1: FAIL, 0: SUCCESS
 * return value of check_closed()
 * 		1: SUCCESS, 0:FAIL
 */
int	check_map_validity(uint32_t **map, int rows, int cols, t_ivec2 *player_pos)
{
	int		i;
	int		j;
	t_ivec2	boundary;
	int		ret;

	boundary = (t_ivec2){cols, rows};
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if ((ft_strchr("NSWE", map[i][j]) && player_pos->x != -1)
				|| (map[i][j] == 51 && check_door(map, i, j, &boundary)))
				return (1);
			if (ft_strchr("NSWE", map[i][j]))
				*player_pos = (t_ivec2){j, i};
			++j;
		}
		++i;
	}
	ret = !check_closed(map, *player_pos, &boundary);
	unmask_map(map, rows, cols);
	return (ret);
}

static int	check_closed(uint32_t **map, t_ivec2 pos, t_ivec2 *boundary)
{
	if (pos.y < 0 || pos.y >= boundary->y || pos.x < 0 || pos.x >= boundary->x
		|| map[pos.y][pos.x] == ' ')
		return (0);
	if (map[pos.y][pos.x] & CHECK_MAP_CHECKED
		|| map[pos.y][pos.x] == CHECK_MAP_WALL)
		return (1);
	map[pos.y][pos.x] |= CHECK_MAP_CHECKED;
	return (check_closed(map, (t_ivec2){pos.x - 1, pos.y - 1}, boundary)
		&& check_closed(map, (t_ivec2){pos.x, pos.y - 1}, boundary)
		&& check_closed(map, (t_ivec2){pos.x + 1, pos.y - 1}, boundary)
		&& check_closed(map, (t_ivec2){pos.x - 1, pos.y}, boundary)
		&& check_closed(map, (t_ivec2){pos.x + 1, pos.y}, boundary)
		&& check_closed(map, (t_ivec2){pos.x - 1, pos.y + 1}, boundary)
		&& check_closed(map, (t_ivec2){pos.x, pos.y + 1}, boundary)
		&& check_closed(map, (t_ivec2){pos.x + 1, pos.y + 1}, boundary));
}

static void	unmask_map(uint32_t **map, int rows, int cols)
{
	int		i;
	int		j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			map[i][j] &= 0b01111111;
			if (map[i][j] == ' ')
				map[i][j] = '1';
			++j;
		}
		++i;
	}
}

static int	check_door(uint32_t **map, int rows, int cols,
	t_ivec2 *boundary)
{
	int	vertical;
	int	horizon;

	vertical = 0;
	horizon = 0;
	if (cols <= 0 || cols >= boundary->x - 1
		|| rows <= 0 || rows >= boundary->y - 1)
		return (1);
	if (map[rows][cols - 1] == '1' && map[rows][cols + 1] == '1')
		horizon = 1;
	if (map[rows - 1][cols] == '1' && map[rows + 1][cols] == '1')
		vertical = 1;
	return (horizon == 0 && vertical == 0);
}
