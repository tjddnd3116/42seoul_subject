/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:00:18 by soum              #+#    #+#             */
/*   Updated: 2021/11/01 16:24:32 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_all_map(t_window *window, int len)
{
	while (len != 0)
	{
		free(window->map[len]);
		len--;
	}
	free(window->map[0]);
	free(window->map);
}

int	stop_game(t_window *window)
{
	ft_putstr_fd("stop game\n", 1);
	fin_game(window);
	return (0);
}

int	fin_game(t_window *window)
{
	mlx_destroy_image(window->mlx, window->img.img);
	mlx_destroy_image(window->mlx, window->obj_player.img);
	mlx_destroy_image(window->mlx, window->obj_item.img);
	mlx_destroy_image(window->mlx, window->obj_wall.img);
	mlx_destroy_image(window->mlx, window->obj_exit.img);
	mlx_destroy_window(window->mlx, window->win);
	free_all_map(window, --window->map_y);
	error_msg_exit("finish game");
	return (0);
}

void	error_msg_exit(char *msg)
{
	ft_putstr_fd(msg, 1);
	exit(1);
}
