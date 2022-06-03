#include "../includes/cub3d.h"

void put_bg_img(t_mlx_data *data)
{
	int pos_x = 0;
	int pos_y = 0;
	for (int grid = 0; grid < 64; grid++)
	{
		if (data->map[grid])
		{
			for (int x = pos_x * GRID; x < pos_x * GRID + GRID; x++)
			{
				for (int y = pos_y * GRID; y < pos_y * GRID + GRID; y++)
					mlx_put_pixel(data->bg_img, x, y, 0xffffffaf);
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

void put_cub_img(t_mlx_data *data)
{
	int y = 0;

	for (; y < HEIGHT / 2; y++)
	{
		for (int x = 0; x < WIDTH; x++)
			mlx_put_pixel(data->cub_img, x, y, 0xffffffff);
	}
	for(; y < HEIGHT ; y++)
	{
		for (int x = 0; x < WIDTH; x++)
			mlx_put_pixel(data->cub_img, x, y, 0x000000ff);
	}
}
