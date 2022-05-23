#include "../includes/cub3d.h"

int draw_wall_pos(t_point *ray, t_mlx_data *data)
{
	double angle;
	int wall_pos;

	angle = ray->angle;
	wall_pos = (int)(ray->x) % GRID;
	wall_pos += (int)(ray->y) % GRID;
	wall_pos = data->wall_txt->width * (double)wall_pos / GRID;
	return (wall_pos);
}

void draw_wall(mlx_image_t *cub, t_point *ray, int idx, int zoom, t_mlx_data *data)
{
	int draw_pixel_y;
	int start_y;
	int end_y;
	double start_x;
	double end_x;
	int wall_pos;
	mlx_texture_t *wall;
	double tmp;
	int tmp2;

	tmp = 0;
	wall = data->wall_txt;
	wall_pos = draw_wall_pos(ray, data);
	draw_pixel_y = ( zoom * HEIGHT / ray->wall_len);
	tmp2 = draw_pixel_y;
	if (ray->wall_len <= zoom)
	{
		tmp = (draw_pixel_y - HEIGHT) / 2.0;
		tmp = (tmp / draw_pixel_y) * 626;
		draw_pixel_y = HEIGHT;
	}
	start_y = (HEIGHT - draw_pixel_y) / 2;
	end_y = start_y + draw_pixel_y;
	start_x = idx * 3.41;
	end_x = idx * 3.41 + 3.41;
	for (double x = start_x; x < end_x ; x++)
	{
		double p_y = tmp;
		for (int y = start_y; y < end_y; y++)
		{
			p_y += 626 / (double)tmp2;
			uint32_t color = *((uint32_t *)wall->pixels + ((int)p_y * 626  + wall_pos));
			color = to_le(color);
			if(ray->is_line)
				mlx_put_pixel(cub, x, y, 0x000000f0);
			else
				mlx_put_pixel(cub, x, y, color);
			}
		}
	}

void cub_draw(t_mlx_data *data)
{
	double angle;

	for (int i = 0; i < 300; i++)
	{
		angle = data->fov.point[i].angle;
		if (angle == 0.0 || angle == 90.0 || angle == 180.0 || angle == 270.0)
			draw_wall(data->cub_img, &data->fov.point[(i + 1) % 300], i, data->zoom, data);
		else
			draw_wall(data->cub_img, &data->fov.point[i], i, data->zoom, data);
	}
}
