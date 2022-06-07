#include "../includes/cub3d.h"

void init_data(t_mlx_data *data)
{
	int map[] = {
		1,1,1,1,1,1,1,1,
		1,0,0,0,0,0,0,1,
		1,0,1,0,1,1,0,0,
		1,0,1,0,0,1,0,1,
		1,1,1,1,1,1,0,1,
		1,0,1,1,0,0,0,1,
		1,0,0,0,0,1,0,1,
		1,1,1,1,1,1,1,1,
	};
	uint32_t xy[2];
	xy[0] = 100;
	xy[1] = 100;
	uint32_t wh[2];
	wh[0] = 100;
	wh[1] = 100;
	data->camera_img = mlx_new_image(data->mlx, IMG_SIZE, IMG_SIZE);
	data->bg_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->cub_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->wall_txt = mlx_load_png("./images/wall2.png");
	mlx_texture_t *gun_txt = mlx_load_png("./images/gun.png");
	data->gun_img = mlx_texture_to_image(data->mlx, gun_txt);
	memset(data->bg_img->pixels, 90, data->bg_img->width * data->bg_img->height * sizeof(int));
	memset(data->camera_img->pixels, 128, data->camera_img->width * data->camera_img->height * sizeof(int));
	memset(data->cub_img->pixels, 90, data->cub_img->width * data->cub_img->height * sizeof(int));
	data->fov.angle = 135;
	data->zoom = 100;
	data->map = (int *)malloc(sizeof(int) * 64);
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
	for (int i = 0; i < 64; i++)
		data->map[i] = map[i];
}

