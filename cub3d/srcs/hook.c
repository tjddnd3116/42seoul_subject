#include "../includes/cub3d.h"
#include <stdint.h>

void mouse_hook(double xdelta, double ydelta, void *param)
{
	t_mlx_data *data;

	data = param;
	(void)xdelta;
	if (ydelta > 0 && data->zoom < 150)
		data->zoom++;
	if (ydelta < 0 && data->zoom > 80)
		data->zoom--;
}

void cursor_hook(double xpos, double ypos, void* param)
{
	t_mlx_data *data;

	data = param;
	(void)ypos;
	if (xpos < WIDTH)
	{
		data->fov.angle -= 4;
		if (data->fov.angle < 0)
			data->fov.angle += 360;
	}
	if (xpos > WIDTH)
	{
		data->fov.angle += 3;
		if (data->fov.angle >= 360)
			data->fov.angle -= 360;
	}
	mlx_set_mouse_pos(data->mlx, WIDTH, HEIGHT / 2);
}

void my_hook(void *param)
{
	t_mlx_data *data;
	double angle;

	data = param;
	memset(data->bg_img->pixels, 90, data->bg_img->width * data->bg_img->height * sizeof(int));
	memset(data->camera_img->pixels, 128, data->camera_img->width * data->camera_img->height * sizeof(int));
	memset(data->cub_img->pixels, 128, data->cub_img->width * data->cub_img->height * sizeof(int));
	put_bg_img(data);
	put_cub_img(data);
	set_fov_pos(data);
	for (int i = 0; i < 300; i++)
	{
		angle = data->fov.point[i].angle;
		if (angle == 0.0 || angle == 90.0 || angle == 180.0 || angle == 270.0)
			fdf_drawline(data->bg_img, &data->fov.point[(i + 1) % 360], &data->fov.camera_pos);
		else
			fdf_drawline(data->bg_img, &data->fov.point[i], &data->fov.camera_pos);
	}
	cub_draw(data);
	mlx_key_hook(data->mlx, key_hook, data);
	mlx_scroll_hook(data->mlx, mouse_hook, data);
}

int find_grid(int x, int y)
{
	int result;

	result = (x / GRID) + (y / GRID) * MAP_SPACE;
	return (result);
}

void key_hook(mlx_key_data_t keydata, void *param)
{
	t_mlx_data *data = param;
	mlx_t	*mlx;
	int angle = data->fov.angle;
	int *c_x = &data->camera_img->instances[0].x;
	int *c_y = &data->camera_img->instances[0].y;
	double move_x;
	double move_y;


	move_x = SPEED * sin(angle * M_PI / 180);
	move_y = SPEED * -cos(angle * M_PI / 180);
	mlx = data->mlx;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_W))
	{
		*c_y += move_y;
		if (data->map[find_grid(*c_x, *c_y)] || data->map[find_grid(*c_x + IMG_SIZE - 1, *c_y)])
			*c_y = ((*c_y) / GRID) * GRID + GRID;
		else if (data->map[find_grid(*c_x, *c_y + IMG_SIZE - 1)] || data->map[find_grid(*c_x + IMG_SIZE - 1, *c_y + IMG_SIZE - 1)])
			*c_y = ((*c_y) / GRID) * GRID + GRID - IMG_SIZE;
		*c_x += move_x;
		if (data->map[find_grid(*c_x, *c_y)] || data->map[find_grid(*c_x, *c_y + IMG_SIZE - 1)])
			*c_x = ((*c_x) / GRID) * GRID + GRID;
		else if (data->map[find_grid(*c_x + IMG_SIZE - 1, *c_y)] || data->map[find_grid(*c_x + IMG_SIZE - 1, *c_y + IMG_SIZE - 1)])
			*c_x = ((*c_x) / GRID) * GRID + GRID - IMG_SIZE;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_S))
	{
		*c_y -=move_y;
		if (data->map[find_grid(*c_x, *c_y)] || data->map[find_grid(*c_x + IMG_SIZE - 1, *c_y)])
			*c_y = ((*c_y) / GRID) * GRID + GRID;
		else if (data->map[find_grid(*c_x, *c_y + IMG_SIZE - 1)] || data->map[find_grid(*c_x + IMG_SIZE - 1, *c_y + IMG_SIZE - 1)])
			*c_y = ((*c_y) / GRID) * GRID + GRID - IMG_SIZE;
		*c_x -= move_x;
		if (data->map[find_grid(*c_x, *c_y)] || data->map[find_grid(*c_x, *c_y + IMG_SIZE - 1)])
			*c_x = ((*c_x) / GRID) * GRID + GRID;
		else if (data->map[find_grid(*c_x + IMG_SIZE - 1, *c_y)] || data->map[find_grid(*c_x + IMG_SIZE - 1, *c_y + IMG_SIZE - 1)])
			*c_x = ((*c_x) / GRID) * GRID + GRID - IMG_SIZE;
	}
}

