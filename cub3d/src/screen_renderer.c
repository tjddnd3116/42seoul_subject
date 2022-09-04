/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_renderer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:07:19 by soum              #+#    #+#             */
/*   Updated: 2022/09/04 15:07:19 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen_renderer.h"

static void		render_main_img(t_mlx_data *data);
static void		draw_minimap_ray(t_mlx_data *data, t_player p0, t_ray p1);
static uint32_t	get_color(t_mlx_data *data, t_col_line_info *info, int32_t y);

static const double	g_grid_to_minimap = (double)MINIMAP_GRID_LEN / GRID_LEN;
static const double	g_angle_diff = g_fov / g_ray_cnt;

void	screen_renderer(void *data)
{
	t_mlx_data	*mlx_data;

	mlx_data = (t_mlx_data *)data;
	key_event(mlx_data);
	cursor_event(mlx_data);
	render_minimap(*mlx_data);
	render_main_img(mlx_data);
	user_interface(mlx_data);
}

static void	render_main_img(t_mlx_data *data)
{
	static double	depth_buffer[SCREEN_WIDTH];
	int32_t			idx;
	t_ray			point;
	t_player		camera;

	idx = 0;
	camera = data->player;
	camera.angle -= g_fov * 0.5;
	while (idx < g_ray_cnt)
	{
		point = detect_wall(camera, data->map);
		point.distance *= cos(camera.angle - data->player.angle);
		draw_col_line(data, point, idx);
		if (idx % 32 == 0)
			draw_minimap_ray(data, camera, point);
		camera.angle += g_angle_diff;
		depth_buffer[idx] = point.distance;
		++idx;
	}
	render_sprite(data, depth_buffer);
}

void	draw_col_line(t_mlx_data *data, t_ray point, int idx)
{
	uint32_t		color;
	int32_t			y;
	t_col_line_info	col_line_info;

	col_line_info.wall_texture = data->texture_list.wall[point.direction];
	col_line_info.range = g_canvas_dist * g_half_screen_height / point.distance;
	col_line_info.pos = get_pos(col_line_info.wall_texture, &point,
			data->map.map[lround(point.y) / GRID_LEN]
		[lround(point.x) / GRID_LEN] >> INFO_BITSHIFT);
	col_line_info.fog_factor = FOG_FACTOR / (point.distance + FOG_FACTOR);
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		color = get_color(data, &col_line_info, y);
		mlx_put_pixel(data->main_img, 2 * idx, y, color);
		mlx_put_pixel(data->main_img, 2 * idx + 1, y, color);
		++y;
	}
}

static void	draw_minimap_ray(t_mlx_data *data, t_player p0, t_ray p1)
{
	t_vec2	origin;
	t_vec2	point;
	double	temp_x;
	double	angle;

	angle = data->player.angle;
	point = (t_vec2){p1.x - p0.x, p1.y - p0.y};
	point.x *= g_grid_to_minimap;
	point.y *= g_grid_to_minimap;
	origin = (t_vec2){MINIMAP_WIDTH >> 1, MINIMAP_HEIGHT >> 1};
	temp_x = point.x;
	point.x = temp_x * cos(angle) + point.y * sin(angle);
	point.y = -temp_x * sin(angle) + point.y * cos(angle);
	point.y += origin.y;
	if (point.y < 0)
	{
		point.x *= origin.y / (origin.y - point.y);
		point.y = 0;
	}
	point.x += origin.x;
	drawline(data->minimap, origin, point);
}

static uint32_t	get_color(t_mlx_data *data, t_col_line_info *info, int32_t y)
{
	double	fog;

	fog = fabs((double)y - g_half_screen_height)
		/ g_half_screen_height;
	if (-info->range + g_half_screen_height > y)
		return (apply_fog(data->texture_list.floor_color, fog));
	else if (info->range + g_half_screen_height <= y)
		return (apply_fog(data->texture_list.ceiling_color, fog));
	y = (y - g_half_screen_height + info->range)
		* info->wall_texture->height / (2 * info->range);
	return (apply_fog_bswap(
			*((uint32_t *)info->wall_texture->pixels
				+ ((int)y * info->wall_texture->width + info->pos)),
			info->fog_factor));
}
