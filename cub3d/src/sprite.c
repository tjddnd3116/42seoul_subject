/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:07:23 by soum              #+#    #+#             */
/*   Updated: 2022/09/07 18:01:02 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "screen_renderer.h"
#include "sprite.h"

static void	load_distance(t_mlx_data *mlx_data);
static void	draw_sprite(t_mlx_data *mlx_data, t_sprite *sprite,
				t_player *player, const double *depth_buffer);
static void	draw_sprite_col_line(t_mlx_data *mlx_data,
				t_sprite *sprite, int32_t idx, double transfer_ratio);
static void	increment_sprite_idx(t_sprite *sprite, uint32_t frame);

void	render_sprite(t_mlx_data *mlx_data, const double *depth_buffer)
{
	static uint32_t	frame;
	t_node			*sprite_node;
	t_sprite		*sprite;

	load_distance(mlx_data);
	dlist_mergesort(&mlx_data->sprite_list, compare);
	sprite_node = mlx_data->sprite_list.head;
	while (sprite_node != NULL)
	{
		sprite = sprite_node->content;
		if ((*sprite->type >> INFO_BITSHIFT) != 0)
		{
			draw_sprite(mlx_data, sprite,
				&mlx_data->player, depth_buffer);
			increment_sprite_idx(sprite, frame);
		}
		sprite_node = sprite_node->next;
	}
	frame++;
}

static void	load_distance(t_mlx_data *mlx_data)
{
	t_player	player;
	t_node		*sprite_node;
	t_sprite	*sprite;

	player = mlx_data->player;
	sprite_node = mlx_data->sprite_list.head;
	while (sprite_node)
	{
		sprite = sprite_node->content;
		sprite->distance = sqrt(pow(sprite->x - player.x, 2)
				+ pow(sprite->y - player.y, 2));
		sprite_node = sprite_node->next;
	}
}

static void	draw_sprite(t_mlx_data *mlx_data, t_sprite *sprite,
		t_player *player, const double *depth_buffer)
{
	double		angle;
	int			idx;
	int			width;
	int32_t		mid;

	angle = atan2(sprite->y - player->y, sprite->x - player->x) + M_PI_2;
	if (angle < 0)
		angle += 2 * M_PI;
	angle -= player->angle;
	mid = g_ray_cnt * (angle + 0.5 * g_fov) / g_fov;
	if (angle > 2 * M_PI - M_PI_2)
		mid = g_ray_cnt * (angle - 2 * M_PI + 0.5 * g_fov) / g_fov;
	else if (-angle > 2 * M_PI - M_PI_2)
		mid = g_ray_cnt * (angle + 2 * M_PI + 0.5 * g_fov) / g_fov;
	width = SPRITE_WIDTH * g_canvas_dist / sprite->distance;
	idx = mid - width;
	while (idx < mid + width)
	{
		if (idx >= 0 && idx < g_ray_cnt && depth_buffer[idx] > sprite->distance)
			draw_sprite_col_line(mlx_data, sprite, idx,
				(double)(idx - mid + width) / (2.0 * width));
		++idx;
	}
}

void	draw_sprite_col_line(t_mlx_data *mlx_data, t_sprite *sprite,
		int32_t idx, double transfer_ratio)
{
	int32_t			pixel_y;
	uint32_t		color;
	t_col_line_info	col_line_info;

	pixel_y = 0;
	col_line_info.texture = sprite->texture[sprite->idx];
	col_line_info.range = g_canvas_dist * g_half_screen_height
		/ sprite->distance;
	col_line_info.pos = col_line_info.texture->width * transfer_ratio;
	col_line_info.fog_factor = FOG_FACTOR / (sprite->distance + FOG_FACTOR);
	while (pixel_y < SCREEN_HEIGHT)
	{
		color = get_sprite_color(&col_line_info, pixel_y);
		if (color != 0)
		{
			mlx_put_pixel(mlx_data->main_img, 2 * idx, pixel_y, color);
			mlx_put_pixel(mlx_data->main_img, 2 * idx + 1, pixel_y, color);
		}
		++pixel_y;
	}
}

static void	increment_sprite_idx(t_sprite *sprite, uint32_t frame)
{
	if (frame % 10 == 1)
		++sprite->idx;
	if (sprite->idx == sprite->size)
		sprite->idx = 0;
}
