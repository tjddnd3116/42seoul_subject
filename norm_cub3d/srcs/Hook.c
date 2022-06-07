/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:09:42 by soum              #+#    #+#             */
/*   Updated: 2022/06/06 15:05:25 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <math.h>
#include <time.h>
#include <stdio.h>

void	get_frametime(void)
{
	static int		frame;
	static clock_t	past;
	static clock_t	now;
	float			frametime;

	now = clock();
	frametime = (float)(now - past) / CLOCKS_PER_SEC;
	past = now;
	printf("fps = %6.2f  frametime = %6.4f\n",
		1 / frametime, frametime);
	++frame;
}

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_mlx_data	*data;

	data = param;
	(void)xdelta;
	if (ydelta > 0 && data->screen.zoom < 150)
		data->screen.zoom++;
	if (ydelta < 0 && data->screen.zoom > 80)
		data->screen.zoom--;
}

void	cursor_hook(double xpos, double ypos, void *param)
{
	t_mlx_data	*data;

	data = param;
	(void)ypos;
	if (xpos < 1280)
	{
		data->player.angle -= ANGLE_SPEED;
		if (data->player.angle < 0)
			data->player.angle += 360;
	}
	else
	{
		data->player.angle += ANGLE_SPEED;
		if (data->player.angle >= 360)
			data->player.angle -= 360;
	}
	mlx_set_mouse_pos(data->mlx, 1280, 0);
}

void	my_hook(void *param)
{
	t_mlx_data	*data;

	data = param;
	memset_all_image(&data->image);
	set_fov_pos(data);
	put_pixels(data);
	/** put_razer_pixel(data, data->image.bg_img); */
	/** put_minimap_pixel(data->image.minimap_img, data->image.bg_img); */
	/** mlx_cursor_hook(data->mlx, cursor_hook, data); */
	/** mlx_scroll_hook(data->mlx, scroll_hook, data); */
	/** mlx_key_hook(data->mlx, key_hook, data); */
	draw_cub(data);
	/** draw_dice(data); */
	/** get_frametime(); */
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_mlx_data	*data;
	double		move_x;
	double		move_y;

	data = param;
	move_x = SPEED * sin(data->player.angle * M_PI / 180);
	move_y = SPEED * -cos(data->player.angle * M_PI / 180);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		player_move(&data->player, move_x, move_y, data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		player_move(&data->player, -move_x, -move_y, data);
}
