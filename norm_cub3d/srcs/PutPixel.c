/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PutPixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:18:58 by soum              #+#    #+#             */
/*   Updated: 2022/06/06 06:54:46 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	put_pixels(t_mlx_data *data)
{
	put_cub_pixel(data);
	/** put_bg_pixel(data->image.bg_img, data->map); */
	/** put_player_pixel(data->image.bg_img, &data->player, \ */
	/**         data->texture.mini_player); */
}

void	put_player_pixel(mlx_image_t *bg_img, t_player *p, mlx_texture_t *p_txt)
{
	int			s_pos[2];
	int			g_pos[2];
	int			xy[2];
	uint32_t	color;

	xy[0] = 0;
	s_pos[0] = p->scaled_mid_pos[0] - (p->scale_size[0] / 2);
	s_pos[1] = p->scaled_mid_pos[1] - (p->scale_size[1] / 2);
	g_pos[0] = s_pos[0] + p->scale_size[0];
	g_pos[1] = s_pos[1] + p->scale_size[1];
	while (s_pos[0] < g_pos[0])
	{
		s_pos[1] = p->scaled_mid_pos[1] - (p->scale_size[1] / 2);
		xy[1] = 0;
		while (s_pos[1] < g_pos[1])
		{
			color = get_player_color(p_txt, p, xy);
			if (!is_invisible(&color))
				mlx_put_pixel(bg_img, s_pos[0], s_pos[1], color);
			s_pos[1]++;
			xy[1]++;
		}
		s_pos[0]++;
		xy[0]++;
	}
}

void	put_bg_pixel(mlx_image_t *bg_img, t_map *map)
{
	int			pos[2];
	int			scaled_pos[2];
	uint32_t	color;

	pos[0] = 0;
	pos[1] = 0;
	while ((uint32_t)pos[1] < bg_img->height)
	{
		pos[0] = 0;
		while ((uint32_t)pos[0] < bg_img->width)
		{
			scale_scn_to_map(pos, scaled_pos, map);
			if (map->map[scaled_pos[1] / GRID][scaled_pos[0] / GRID] == '1')
				color = 0x000000af;
			else
				color = 0xffffffaf;
			if ((scaled_pos[1] / GRID + scaled_pos[0] / GRID) % 2)
				color -= 40;
			mlx_put_pixel(bg_img, pos[0], pos[1], color);
			pos[0]++;
		}
		pos[1]++;
	}
}

void	put_minimap_pixel(mlx_image_t *mini_img, mlx_image_t *bg_img)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	color;

	y = 0;
	while (y < mini_img->height)
	{
		x = 0;
		while (x < mini_img->width)
		{
			color = *((uint32_t *)bg_img->pixels + (x * 5 + y * SCREEN_W * 5));
			color = to_le(color);
			mlx_put_pixel(mini_img, x, y, color);
			x++;
		}
		y++;
	}
}

void	put_cub_pixel(t_mlx_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < 720)
	{
		x = 0;
		while (x < 2560)
			mlx_put_pixel(data->image.cub_img, x++, y, 0xffffffaf);
		y++;
	}
	while (y < 1440)
	{
		x = 0;
		while (x < 2560)
			mlx_put_pixel(data->image.cub_img, x++, y, 0xffffff0f);
		y++;
	}
}
