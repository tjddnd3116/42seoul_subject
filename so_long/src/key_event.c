/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:15:39 by soum              #+#    #+#             */
/*   Updated: 2021/11/01 16:24:29 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_press(int keycode, t_window *window)
{
	if (keycode == 53)
		stop_game(window);
	else if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13)
		move_player(window, keycode);
	return (1);
}

void	key_event(t_window *window)
{
	window->move_count = 0;
	mlx_hook(window->win, 2, 1, key_press, window);
	mlx_hook(window->win, 17, 0, stop_game, window);
}
