#include "../includes/cub3d.h"
#include <stdint.h>

int32_t detect_y_wall(int32_t *y_wall_x, int32_t *y_wall_y, t_mlx_data *data)
{
	int32_t ray_x =   

}

int32_t detect_x_wall(int32_t *x_wall_x, int32_t *x_wall_y, t_mlx_data *data)
{

}

void detect_wall(t_point *point, t_mlx_data *data)
{
	int32_t y_wall_y;
	int32_t y_wall_x;
	int32_t x_wall_x;
	int32_t x_wall_y;
	int32_t a_len;
	int32_t b_len;
	a_len = detect_y_wall(&y_wall_x, &y_wall_y, data);
	b_len = detect_x_wall(&x_wall_x, &x_wall_y, data);
	if (a_len < b_len)
	{
		point->x = y_wall_x;
		point->y = y_wall_y;
	}
	else {
		point->x = x_wall_x;
		point->y= y_wall_y;
	}
}
