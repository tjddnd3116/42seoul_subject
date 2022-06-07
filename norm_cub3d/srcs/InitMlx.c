/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InitMlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:39:30 by soum              #+#    #+#             */
/*   Updated: 2022/06/07 23:14:46 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	init_screen(t_mlx_data *data)
{
	t_screen	*screen;

	screen = &data->screen;
	screen->screen_w = SCREEN_W;
	screen->screen_h = SCREEN_H;
	data->mlx = mlx_init(SCREEN_W, SCREEN_H, "soum_cub3d", true);
	screen->zoom = 200;
	screen->toggle_minimap = 0;
	return (0);
}

int	init_txt(t_mlx_data *data)
{
	t_texture	*texture;

	texture = &data->texture;
	texture->mini_player = mlx_load_png("./images/mini_player.png");
	texture->n_wall_txt = mlx_load_png(data->texture.n_wall_path);
	texture->s_wall_txt = mlx_load_png(data->texture.s_wall_path);
	texture->w_wall_txt = mlx_load_png(data->texture.w_wall_path);
	texture->e_wall_txt = mlx_load_png(data->texture.e_wall_path);
	return (0);
}

int	init_img(t_mlx_data *data)
{
	t_image	*image;

	image = &data->image;
	image->minimap_img = mlx_new_image(data->mlx, MINIMAP_W, MINIMAP_H);
	image->cub_img = mlx_new_image(data->mlx, SCREEN_W, SCREEN_H);
	return (0);
}
