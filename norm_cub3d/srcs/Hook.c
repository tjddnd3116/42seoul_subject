/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:09:42 by soum              #+#    #+#             */
/*   Updated: 2022/06/11 16:43:11 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_mlx_data	*data;

	data = param;
	(void)xdelta;
	if (ydelta > 0 && data->screen.zoom < 40)
		data->screen.zoom++;
	if (ydelta < 0 && data->screen.zoom > 20)
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
	if (data->map.door_ani.is_door_action)
		door_ani(&data->map.door_ani, &data->map);
	set_fov_pos(data);
	memset_all_image(&data->image);
	put_pixels(data);
	draw_cub(data);
	mlx_cursor_hook(data->mlx, cursor_hook, data);
	mlx_scroll_hook(data->mlx, scroll_hook, data);
	mlx_key_hook(data->mlx, key_hook, data);
	/** get_frametime(); */
}

void	change_angle(t_player *p, char key)
{
	if (key == 'A')
	{
		p->angle -= ANGLE_SPEED;
		if (p->angle < 0)
			p->angle += 360;
	}
	if (key == 'D')
	{
		p->angle += ANGLE_SPEED;
		if (p->angle >= 360)
			p->angle -= 360;
	}
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
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		change_angle(&data->player, 'A');
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		change_angle(&data->player, 'D');
	if (mlx_is_key_down(data->mlx, MLX_KEY_M))
		data->screen.toggle_minimap = !data->screen.toggle_minimap;
	if (mlx_is_key_down(data->mlx, MLX_KEY_F) && data->player.near_door)
		act_door(&data->map, data->pnt);
}
