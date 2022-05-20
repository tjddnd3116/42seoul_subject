#include "../includes/cub3d.h"

void init_data(t_mlx_data *data)
{
	data->camera_img = mlx_new_image(data->mlx, IMG_SIZE, IMG_SIZE);
	data->bg_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->cub_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	memset(data->bg_img->pixels, 90, data->bg_img->width * data->bg_img->height * sizeof(int));
	memset(data->camera_img->pixels, 128, data->camera_img->width * data->camera_img->height * sizeof(int));
	memset(data->cub_img->pixels, 90, data->cub_img->width * data->cub_img->height * sizeof(int));
	data->fov.angle = 0;
}

