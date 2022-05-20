#include "../includes/cub3d.h"

void draw_wall(mlx_image_t *cub, t_point *ray, int idx)
{
	int draw_pixel_y;
	int start_y;
	int end_y;
	double start_x;
	double end_x;


	ray->wall_len *= cos(ray->angle * M_PI / 180);
	draw_pixel_y = ( 128 * HEIGHT / ray->wall_len);
	if (ray->wall_len <= 128)
		draw_pixel_y = HEIGHT;
	start_y = (HEIGHT - draw_pixel_y) / 2;
	end_y = start_y + draw_pixel_y;
	start_x = idx * 3.41;
	end_x = idx * 3.41 + 3.41;
	for (double x = start_x; x < end_x ; x++)
	{
		for (int y = start_y; y < end_y; y++)
		{
			if (ray->is_line == 1)
				mlx_put_pixel(cub, x, y, 0x000000f0);
			else
				mlx_put_pixel(cub, x, y, 0xfffffff0);
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
			draw_wall(data->cub_img, &data->fov.point[(i + 1) % 300], i);
		else
			draw_wall(data->cub_img, &data->fov.point[i], i);
	}
}
