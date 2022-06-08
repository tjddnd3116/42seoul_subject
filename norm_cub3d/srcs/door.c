/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:52:52 by soum              #+#    #+#             */
/*   Updated: 2022/06/08 23:21:11 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	open_door(t_map *map_data, t_point *pnt)
{
	int		grid_xy[2];
	char	**map;
	t_point	mid_pnt;

	mid_pnt = pnt[PNT_CNT / 2];
	map = map_data->map;
	grid_xy[0] = mid_pnt.map_x / GRID;
	if (mid_pnt.type == 'W')
		grid_xy[0] = (mid_pnt.map_x - 1) / GRID;
	grid_xy[1] = mid_pnt.map_y / GRID;
	if (mid_pnt.type == 'N')
		grid_xy[1] = (mid_pnt.map_y - 1) / GRID;
	if (map[grid_xy[1]][grid_xy[0]] == '2')
		map[grid_xy[1]][grid_xy[0]] = '0';
}

int	is_near_door(t_point *pnt)
{
	t_point	mid_pnt;

	mid_pnt = pnt[PNT_CNT / 2];
	if (mid_pnt.is_door && mid_pnt.wall_len <= GRID)
		return (1);
	return (0);
}
