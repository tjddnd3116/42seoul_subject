#include "../includes/cub3d.h"
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

int is_wall(int32_t *wall_x, int32_t *wall_y, int *map)
{
	int grid_x;
	int grid_y;

	if (*wall_x < 0)
		*wall_x = 0;
	if (*wall_y < 0)
		*wall_y = 0;
	grid_x = *wall_x / GRID;
	grid_y = *wall_y / GRID;
	if (map[grid_y * MAP_SPACE + grid_x] == 1)
		return (1);
	return (0);

}

double detect_y_wall(int32_t *y_wall_x, int32_t *y_wall_y, t_mlx_data *data, int idx)
{
	int32_t ray_x;
	int32_t ray_y;
	int32_t wall_x;
	int32_t wall_y;
	double degree;
	double angle;
	int grid_y;

	angle = data->fov.point[idx].angle;
	degree = angle * (M_PI / 180);
	ray_x = data->fov.camera_pos.x;
	ray_y = data->fov.camera_pos.y - 1;
	grid_y = ray_y / GRID;
	while (grid_y >= 0 && grid_y < MAP_SPACE)
	{
		if (angle < 90 || 270 < angle)
			wall_y = grid_y * GRID - 1;
		else
			wall_y = grid_y * GRID + GRID;
		if (angle == 90 || angle == 270)
			wall_x = ray_x;
		else
			wall_x = ray_x + (ray_y - wall_y) * tan(degree);
		if (is_wall(&wall_x, &wall_y, data->map))
		{
			*y_wall_x = wall_x;
			*y_wall_y = wall_y;
			return (sqrt(pow(wall_x - ray_x, 2.0) + pow(wall_y - ray_y, 2.0)));
		}
		if (angle < 90 || angle > 270)
			grid_y--;
		else
			grid_y++;
	}
	return (sqrt(pow(wall_x - ray_x, 2.0) + pow(wall_y - ray_y, 2.0)));
}

double detect_x_wall(int32_t *x_wall_x, int32_t *x_wall_y, t_mlx_data *data, int idx)
{
	int32_t ray_x;
	int32_t ray_y;
	int32_t wall_x;
	int32_t wall_y;
	double degree;
	int grid_x;
	double angle;

	angle = data->fov.point[idx].angle;
	degree = angle * (M_PI / 180);
	ray_x = data->fov.camera_pos.x - 1;
	ray_y = data->fov.camera_pos.y;
	grid_x = ray_x / GRID;
	while(grid_x >= 0 && grid_x < MAP_SPACE)
	{
		if (angle < 180)
			wall_x = grid_x * GRID + GRID;
		else
			wall_x = grid_x * GRID - 1;
		if (angle == 180.0 || angle == 0.0)
			wall_y = ray_y;
		else
			wall_y = ray_y + (ray_x - wall_x) / tan(degree);
		if (is_wall(&wall_x, &wall_y, data->map))
		{
			*x_wall_x = wall_x;
			*x_wall_y = wall_y;
			return (sqrt(pow(wall_x - ray_x, 2.0) + pow(wall_y - ray_y, 2.0)));
		}
		if (angle < 180)
			grid_x++;
		else
			grid_x--;
	}
	return (sqrt(pow(wall_x - ray_x, 2.0) + pow(wall_y - ray_y, 2.0)));
}

void detect_wall(t_point *point, t_mlx_data *data, int i)
{
	int32_t y_wall_y;
	int32_t y_wall_x;
	int32_t x_wall_x;
	int32_t x_wall_y;
	double a_len;
	double b_len;
	a_len = detect_y_wall(&y_wall_x, &y_wall_y, data, i);
	b_len = detect_x_wall(&x_wall_x, &x_wall_y, data, i);
	if (a_len < b_len)
	{
		if (y_wall_x % GRID == 0 || y_wall_x % GRID == 1 || y_wall_x % GRID == 127)
			point->is_line = 1;
		else
			point->is_line = 0;
		point->x = y_wall_x;
		point->y = y_wall_y;
		point->wall_len = a_len * cos((data->fov.angle - point->angle)  * M_PI / 180);
		point->grid_x = y_wall_x / GRID;
		point->grid_y = y_wall_y / GRID;
	}
	else {
		if (x_wall_y % GRID == 0 || x_wall_y % GRID == 1 || x_wall_y % GRID == 127)
			point->is_line = 1;
		else
			point->is_line = 0;
		point->x = x_wall_x;
		point->y = x_wall_y;
		point->wall_len = b_len * cos((data->fov.angle - point->angle) * (M_PI / 180));
		point->grid_x = x_wall_x / GRID;
		point->grid_y = x_wall_y / GRID;
	}
}
