/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:52:52 by soum              #+#    #+#             */
/*   Updated: 2022/06/10 23:21:13 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_door_action(t_ray *pnt, t_map *map_data)
{
	t_door	*door;

	door = &map_data->door_ani;
	pnt->is_door = 2;
	if (pnt->wall_len >= GRID * 2)
		return (1);
	if (!door->is_door_action)
		return (1);
	if (pnt->type == 'N' || pnt->type == 'S')
	{
		if (pnt->xy[0] >= door->start_x && pnt->xy[0] <= door->end_x)
			return (1);
	}
	else if (pnt->type == 'W' || pnt->type == 'E')
	{
		if (pnt->xy[1] >= door->start_y && pnt->xy[1] <= door->end_y)
			return (1);
	}
	pnt->is_door = 1;
	return (0);
}

void	set_door_ani(t_door *door, int *grid_xy, char act)
{
	door->is_door_action = 1;
	door->act = act;
	if (act == 'o')
	{
		door->start_x = grid_xy[0] * GRID;
		door->start_y = grid_xy[1] * GRID;
		door->end_x = door->start_x + GRID - 1;
		door->end_y = door->start_y + GRID - 1;
	}
	else if (act == 'c')
	{
		door->start_x = grid_xy[0] * GRID + GRID - 1;
		door->start_y = grid_xy[1] * GRID + GRID - 1;
		door->end_x = grid_xy[0] * GRID;
		door->end_y = grid_xy[1] * GRID;

	}
	door->grid_x = grid_xy[0];
	door->grid_y = grid_xy[1];
}

void	door_ani(t_door *door, t_map *map_data)
{
	double	add;

	add = GRID / 15.0;
	if (door->act == 'c')
		add *= -1;
	door->start_x += add;
	door->start_y += add;
	if (door->start_x == door->end_x)
	{
		door->is_door_action = 0;
		door->start_x = 0 ;
		door->end_x = 0;
		door->start_y = 0;
		door->end_y = 0;
		map_data->map[door->grid_y][door->grid_x] = '2';
	}
}

void	act_door(t_map *map_data, t_point *pnt)
{
	int		grid_xy[2];
	char	**map;
	t_point	mid_pnt;

	if (map_data->door_ani.is_door_action)
		return ;
	mid_pnt = pnt[PNT_CNT / 2];
	map = map_data->map;
	grid_xy[0] = mid_pnt.map_x / GRID;
	if (mid_pnt.type == 'W')
		grid_xy[0] = (mid_pnt.map_x - 1) / GRID;
	grid_xy[1] = mid_pnt.map_y / GRID;
	if (mid_pnt.type == 'N')
		grid_xy[1] = (mid_pnt.map_y - 1) / GRID;
	if (map[grid_xy[1]][grid_xy[0]] == '3')
		set_door_ani(&map_data->door_ani, grid_xy, 'o');
	if (map[grid_xy[1]][grid_xy[0]] == '2')
		set_door_ani(&map_data->door_ani, grid_xy, 'c');
}

int	is_near_door(t_point *pnt)
{
	t_point	mid_pnt;

	mid_pnt = pnt[PNT_CNT / 2];
	if (mid_pnt.is_door && mid_pnt.wall_len <= GRID * 2)
		return (mid_pnt.is_door);
	return (0);
}
