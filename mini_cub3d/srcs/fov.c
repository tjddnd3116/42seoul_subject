#include "../includes/cub3d.h"

void set_fov_pos(t_mlx_data *data)
{
	data->fov.camera_pos.x = (data->camera_img->instances[0].x + IMG_SIZE / 2.0);
	data->fov.camera_pos.y = (data->camera_img->instances[0].y + IMG_SIZE / 2.0);
	data->fov.camera_pos.color = 0xff0000ff;
	int start_angle;

	start_angle = (360 + (data->fov.angle - 30)) % 360;
	for (int i = 0; i < 300; i++)
	{
		data->fov.point[i].angle = start_angle + i * 0.2;
		if (data->fov.point[i].angle >= 360.0)
			data->fov.point[i].angle -= 360.0;
		data->fov.point[i].color = 0xff0000ff;
		detect_wall(&data->fov.point[i], data, i);
	}
}
