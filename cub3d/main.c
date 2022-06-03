#include "./includes/cub3d.h"
#include "MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>

int main(void)
{
	t_mlx_data data;

	data.mlx = mlx_init(WIDTH * 2, HEIGHT, "soum_cub3d", true);
	if (!data.mlx)
		exit(EXIT_FAILURE);
	init_data(&data);
	put_bg_img(&data);
	/** mlx_resize_image(data.bg_img, 400, 400); */
	mlx_image_to_window(data.mlx, data.bg_img, 0, 0);
	mlx_image_to_window(data.mlx, data.cub_img, WIDTH, 0);
	mlx_image_to_window(data.mlx, data.camera_img, 129, 129);
	mlx_cursor_hook(data.mlx, cursor_hook, &data);
	mlx_loop_hook(data.mlx, my_hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
}
