#include "../includes/cub3d.h"

void draw_wall(mlx_image_t *cub, t_point *ray, int idx)
{
	/** double weight; */
	int draw_pixel_y;
	int start_y;
	int end_y;
	int start_x;
	int end_x;

	draw_pixel_y = ( 128 / ray->wall_len) * HEIGHT;
	if (ray->wall_len <= 128)
		draw_pixel_y = HEIGHT;
	start_y = (HEIGHT - draw_pixel_y) / 2;
	end_y = start_y + draw_pixel_y;
	start_x = idx * 3;
	end_x = idx * 3 + 3;
	/** if (idx == 30) */
	/**     printf("wall_len : %f, start_y : %d, draw_pixel_y : %d\n", ray->wall_len, start_y, draw_pixel_y); */
	for (int x = start_x; x < end_x ; x++)
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
		// 임시
		angle = data->fov.point[i].angle;
		if (angle == 0.0 || angle == 90.0 || angle == 180.0 || angle == 270.0)
			draw_wall(data->cub_img, &data->fov.point[(i+1) % 300], i);
		else
			draw_wall(data->cub_img, &data->fov.point[i], i);
	}
}
