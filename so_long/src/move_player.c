/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:55:09 by soum              #+#    #+#             */
/*   Updated: 2021/11/01 16:19:59 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_count(t_window *window, int move_count)
{
	ft_putstr_fd("move count : ", 1);
	ft_putnbr_fd(move_count, 1);
	ft_putchar_fd('\n', 1);
}

void	change_map(t_window *window, char obj, t_pos *pos, char **map)
{
	if (obj == 'C')
		window->item_count--;
	if (obj == 'E' && window->item_count == 0)
	{
		print_count(window, ++window->move_count);
		fin_game(window);
	}
	map[window->player.y][window->player.x] = '0';
	window->player.x = pos->x;
	window->player.y = pos->y;
	map[window->player.y][window->player.x] = 'P';
	print_count(window, ++window->move_count);
}

void	move_pos(t_window *window, int x, int y)
{
	char	**map;
	t_pos	pos;

	pos.x = window->player.x + x;
	pos.y = window->player.y + y;
	map = window->map;
	if (map[pos.y][pos.x] == '0')
		change_map(window, map[pos.y][pos.x], &pos, map);
	else if (map[pos.y][pos.x] == 'C')
		change_map(window, map[pos.y][pos.x], &pos, map);
	else if (map[pos.y][pos.x] == 'E' && window->item_count == 0)
		change_map(window, map[pos.y][pos.x], &pos, map);
	render_image(window);
	rendering(window);
}

void	move_player(t_window *window, int keycode)
{
	if (keycode == 13)
		move_pos(window, 0, -1);
	else if (keycode == 0)
		move_pos(window, -1, 0);
	else if (keycode == 1)
		move_pos(window, 0, 1);
	else if (keycode == 2)
		move_pos(window, 1, 0);
}
