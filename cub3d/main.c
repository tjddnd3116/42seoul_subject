#include "./includes/cub3d.h"
#include "MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>

int map[]=           //the map array. Edit to change level but keep the outer walls
{
 1,1,1,1,1,1,1,1,
 1,0,0,0,0,0,0,1,
 1,0,1,0,0,1,0,1,
 1,0,1,0,0,0,0,1,
 1,0,0,0,0,0,0,1,
 1,0,1,0,0,1,1,1,
 1,0,0,0,0,1,1,1,
 1,1,1,1,1,1,1,1,
};

int main(void)
{
	t_mlx_data data;
	data.map = map;

	data.mlx = mlx_init(WIDTH * 2, HEIGHT, "soum_cub3d", true);
	if (!data.mlx)
		exit(EXIT_FAILURE);
	init_data(&data);
	put_bg_img(&data);
	mlx_image_to_window(data.mlx, data.bg_img, 0, 0);
	mlx_image_to_window(data.mlx, data.cub_img, WIDTH, 0);
	mlx_image_to_window(data.mlx, data.camera_img, 129, 129);
	mlx_image_to_window(data.mlx, data.gun_img, WIDTH + (WIDTH / 2) - 50, HEIGHT - 200);
	mlx_cursor_hook(data.mlx, cursor_hook, &data);
	mlx_loop_hook(data.mlx, my_hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
}
