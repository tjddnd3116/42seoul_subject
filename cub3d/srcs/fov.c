#include "../includes/cub3d.h"

void set_fov_pos(t_mlx_data *data)
{
	data->fov.camera_pos.x = (data->camera_img->instances[0].x + IMG_SIZE / 2.0);
	data->fov.camera_pos.y = (data->camera_img->instances[0].y + IMG_SIZE / 2.0);
	data->fov.camera_pos.color = 0xff0000ff;
	for (int i = 0; i < 360; i++)
		detect_wall(&data->fov.point[i], data, i);
}
