/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:24:01 by soum              #+#    #+#             */
/*   Updated: 2022/06/07 22:44:14 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	pos_to_grid(int pos, int cub_size, int size)
{
	return ((pos + size) / cub_size);
}

int	is_y_grid(char **map, t_player *p)
{
	int	grid_x1;
	int	grid_y1;
	int	grid_x2;
	int	grid_y2;

	grid_x1 = pos_to_grid(p->pos[0], GRID, 0);
	grid_y1 = pos_to_grid(p->pos[1], GRID, 0);
	grid_x2 = pos_to_grid(p->pos[0], GRID, PLAYER_SIZE - 1);
	grid_y2 = pos_to_grid(p->pos[1], GRID, PLAYER_SIZE - 1);
	if (map[grid_y1][grid_x1] == '1' || map[grid_y1][grid_x2] == '1')
		return ((p->pos[1] / GRID) * GRID + GRID);
	else if (map[grid_y2][grid_x1] == '1' || map[grid_y2][grid_x2] == '1')
		return ((p->pos[1] / GRID) * GRID + GRID - PLAYER_SIZE);
	return (0);
}

int	is_x_grid(char **map, t_player *p)
{
	int	grid_x1;
	int	grid_y1;
	int	grid_x2;
	int	grid_y2;

	grid_x1 = pos_to_grid(p->pos[0], GRID, 0);
	grid_y1 = pos_to_grid(p->pos[1], GRID, 0);
	grid_x2 = pos_to_grid(p->pos[0], GRID, PLAYER_SIZE - 1);
	grid_y2 = pos_to_grid(p->pos[1], GRID, PLAYER_SIZE - 1);
	if (map[grid_y1][grid_x1] == '1' || map[grid_y2][grid_x1] == '1')
		return ((p->pos[0] / GRID) * GRID + GRID);
	else if (map[grid_y1][grid_x2] == '1' || map[grid_y2][grid_x2] == '1')
		return ((p->pos[0] / GRID) * GRID + GRID - PLAYER_SIZE);
	return (0);
}

void	player_move(t_player *p, double x, double y, t_mlx_data *data)
{
	int		*p_x;
	int		*p_y;
	char	**map;
	int		re_pos;

	map = data->map.map;
	p_x = &p->pos[0];
	p_y = &p->pos[1];
	*p_y += y;
	re_pos = is_y_grid(map, p);
	if (re_pos)
		*p_y = re_pos;
	*p_x += x;
	re_pos = is_x_grid(map, p);
	if (re_pos)
		*p_x = re_pos;
	player_pos_scale(p, &data->map);
}
