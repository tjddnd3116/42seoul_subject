#include "../includes/cub3d.h"

void my_hook(void *param)
{
	t_mlx_data *data;
	data = param;
	memset(data->bg_img->pixels, 90, data->bg_img->width * data->bg_img->height * sizeof(int));
	memset(data->camera_img->pixels, 128, data->camera_img->width * data->camera_img->height * sizeof(int));
	memset(data->cub_img->pixels, 128, data->cub_img->width * data->cub_img->height * sizeof(int));
	put_bg_img(data);
	set_fov_pos(data);
	for (int i = 0; i < 300; i++)
		fdf_drawline(data->bg_img, &data->fov.point[i], &data->fov.camera_pos);
	cub_draw(data);
}

void key_hook(mlx_key_data_t keydata, void *param)
{
	t_mlx_data *data = param;
	mlx_t	*mlx;
	int grid_x1 = 0;
	int grid_y1 = 0;
	int grid_x2 = 0;
	int grid_y2 = 0;


	mlx = data->mlx;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_W))
	{
		data->camera_img->instances[0].y -= SPEED;
		grid_y1 = data->camera_img->instances[0].y / GRID;
		grid_x1 = data->camera_img->instances[0].x / GRID;
		grid_x2 = (data->camera_img->instances[0].x + IMG_SIZE / 2) / GRID;
		if (data->map[grid_x1 + grid_y1 * 8] == 1 || data->map[(grid_x2 + grid_y1 * 8)] == 1)
			data->camera_img->instances[0].y += SPEED;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_S))
	{
		data->camera_img->instances[0].y += SPEED;
		grid_y1 = (data->camera_img->instances[0].y + IMG_SIZE / 2) / GRID;
		grid_x1 = data->camera_img->instances[0].x / GRID;
		grid_x2 = (data->camera_img->instances[0].x + IMG_SIZE / 2) / GRID;
		if (data->map[grid_x1 + grid_y1 * 8] == 1 || data->map[(grid_x2 + grid_y1 * 8)] == 1)
			data->camera_img->instances[0].y -= SPEED;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_A))
	{
		data->camera_img->instances[0].x -= SPEED;
		grid_y1 = data->camera_img->instances[0].y / GRID;
		grid_x1 = data->camera_img->instances[0].x / GRID;
		grid_y2 = (data->camera_img->instances[0].y + IMG_SIZE / 2) / GRID;
		if (data->map[grid_x1 + grid_y1 * 8] == 1 || data->map[(grid_x1 + grid_y2 * 8)] == 1)
			data->camera_img->instances[0].x += SPEED;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_D))
	{
		data->camera_img->instances[0].x += SPEED;
		grid_y1 = data->camera_img->instances[0].y / GRID;
		grid_x1 = (data->camera_img->instances[0].x + IMG_SIZE / 2) / GRID;
		grid_y2 = (data->camera_img->instances[0].y + IMG_SIZE / 2) / GRID;
		if (data->map[grid_x1 + grid_y1 * 8] == 1 || data->map[(grid_x1 + grid_y2 * 8)] == 1)
			data->camera_img->instances[0].x -= SPEED;
	}
	if (mlx_is_key_down(mlx,MLX_KEY_E))
	{
		data->fov.angle += 1;
		if (data->fov.angle == 360)
			data->fov.angle = 0;
	}
	if (mlx_is_key_down(mlx,MLX_KEY_Q))
	{
		data->fov.angle -= 1;
		if (data->fov.angle == 0)
			data->fov.angle = 360;
	}
}
