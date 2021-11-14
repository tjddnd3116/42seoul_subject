/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:32:57 by soum              #+#    #+#             */
/*   Updated: 2021/11/01 16:21:58 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_all_image(t_window *window)
{
	window->obj_wall.img = mlx_xpm_file_to_image(window->mlx, \
			"./image/wall.xpm", &window->obj_wall.width, \
			&window->obj_wall.height);
	window->obj_wall.addr = mlx_get_data_addr(window->obj_wall.img, \
			&window->obj_wall.bpp, &window->obj_wall.line_len, \
			&window->obj_wall.endian);
	window->obj_player.img = mlx_xpm_file_to_image(window->mlx, \
			"./image/player.xpm", &window->obj_player.width, \
			&window->obj_player.height);
	window->obj_player.addr = mlx_get_data_addr(window->obj_player.img, \
			&window->obj_player.bpp, &window->obj_player.line_len, \
			&window->obj_player.endian);
	window->obj_item.img = mlx_xpm_file_to_image(window->mlx, \
			"./image/item.xpm", &window->obj_item.width, \
			&window->obj_item.height);
	window->obj_item.addr = mlx_get_data_addr(window->obj_item.img, \
			&window->obj_item.bpp, &window->obj_item.line_len, \
			&window->obj_item.endian);
	window->obj_exit.img = mlx_xpm_file_to_image(window->mlx, \
			"./image/exit.xpm", &window->obj_exit.width, \
			&window->obj_exit.height);
	window->obj_exit.addr = mlx_get_data_addr(window->obj_exit.img, \
			&window->obj_exit.bpp, &window->obj_exit.line_len, \
			&window->obj_exit.endian);
}

int	get_cube_size(t_window *window, t_pos screen_size, int map_x, int map_y)
{
	int	cube_x;
	int	cube_y;

	cube_x = screen_size.x / map_x;
	cube_y = screen_size.y / map_y;
	if (cube_x <= cube_y)
	{
		if (cube_x < 1)
			return (1);
		return (cube_x);
	}
	else
	{
		if (cube_y < 1)
			return (1);
		return (cube_y);
	}
}

void	init_window(t_window *window)
{
	window->screen_size.x = 1440;
	window->screen_size.y = 800;
	window->cube_size = get_cube_size(window, window->screen_size, \
			window->map_x, window->map_y);
	window->screen_size.x = window->cube_size * window->map_x;
	window->screen_size.y = window->cube_size * window->map_y;
	window->win = mlx_new_window(window->mlx, window->screen_size.x, \
			window->screen_size.y, "soum's so_long");
	window->img.img = mlx_new_image(window->mlx, \
			window->screen_size.x, window->screen_size.y);
}

void	create_window(t_window *window)
{
	window->mlx = mlx_init();
	init_window(window);
	window->img.addr = mlx_get_data_addr(window->img.img, \
			&window->img.bpp, &window->img.line_length, \
			&window->img.endian);
	load_all_image(window);
	key_event(window);
}
