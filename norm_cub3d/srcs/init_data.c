/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InitData.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:20:58 by soum              #+#    #+#             */
/*   Updated: 2022/06/12 19:46:46 by soum             ###   ########.fr       */
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
	if (!data->mlx)
		error_msg("mlx init error", MLX_INIT_ERROR, data);
	screen->zoom = 350;
	screen->toggle_minimap = 0;
	return (0);
}

int	init_txt(t_mlx_data *data)
{
	t_texture	*texture;

	texture = &data->texture;
	texture->n_wall_txt = mlx_load_png(data->texture.n_wall_path);
	if (!texture->n_wall_txt)
		error_msg("png file load error", MLX_INIT_ERROR, data);
	texture->s_wall_txt = mlx_load_png(data->texture.s_wall_path);
	if (!texture->s_wall_txt)
		error_msg("png file load error", MLX_INIT_ERROR, data);
	texture->w_wall_txt = mlx_load_png(data->texture.w_wall_path);
	if (!texture->w_wall_txt)
		error_msg("png file load error", MLX_INIT_ERROR, data);
	texture->e_wall_txt = mlx_load_png(data->texture.e_wall_path);
	if (!texture->e_wall_txt)
		error_msg("png file load error", MLX_INIT_ERROR, data);
	texture->door_txt = mlx_load_png("./images/new_door.png");
	if (!texture->door_txt)
		error_msg("png file load error", MLX_INIT_ERROR, data);
	return (0);
}

int	init_img(t_mlx_data *data)
{
	t_image	*image;

	image = &data->image;
	image->minimap_img = mlx_new_image(data->mlx, MINIMAP_W, MINIMAP_H);
	if (!image->minimap_img)
		error_msg("mlx image create error", MLX_INIT_ERROR, data);
	image->cub_img = mlx_new_image(data->mlx, SCREEN_W, SCREEN_H);
	if (!image->cub_img)
		error_msg("mlx image create error", MLX_INIT_ERROR, data);
	return (0);
}

void	check_file(t_mlx_data *data, char *map_path)
{
	if (!ft_strnstr(map_path, ".cub", ft_strlen(map_path)))
		error_msg("check file name or path", FILE_NAME_ERROR, data);
}

void	init_data(t_mlx_data *data, char *map_path)
{
	data->map.map_path = map_path;
	check_file(data, map_path);
	init_fc(data);
	init_wall_txt(data);
	init_map(data);
	init_screen(data);
	init_img(data);
	init_txt(data);
	init_player(data);
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
}
