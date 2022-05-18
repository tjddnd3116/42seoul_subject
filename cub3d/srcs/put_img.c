#include "../includes/cub3d.h"

void put_bg_img(t_mlx_data *data)
{
	int pos_x = 0;
	int pos_y = 0;
	for (int grid = 0; grid < 64; grid++)
	{
		if (data->map[grid] == 1)
		{
			for (int x = pos_x * GRID; x < pos_x * GRID + GRID; x++)
			{
				for (int y = pos_y * GRID; y < pos_y * GRID + GRID; y++)
					mlx_put_pixel(data->bg_img, x, y, 0xfffffff0);
			}
		}
		pos_x++;
		if (pos_x == 8)
		{
			pos_x = 0;
			pos_y++;
		}
	}
	for (int i = 0; i < HEIGHT; i++)
	{
		 for (int j = 0; j < WIDTH; j++)
		 {
			 if (i % GRID == 0 || j % GRID == 0)
				 mlx_put_pixel(data->bg_img, j, i, 0x000000ff);
		 }
	}
}
