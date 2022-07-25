#include "../includes/cub3d.h"

static void	swap_point(t_point **p0, t_point **p1);
static void	drawline_low_up(mlx_image_t *img, t_point p0, t_point p1);
static void	drawline_low_down(mlx_image_t *img, t_point p0, t_point p1);
static void	drawline_high_up(mlx_image_t *img, t_point p0, t_point p1);
static void	drawline_high_down(mlx_image_t *img, t_point p0, t_point p1);


void	fdf_drawline(mlx_image_t *img, t_point *p0, t_point *p1)
{
	int		dy;
	if ((int)(p1->x - p0->x) < 0)
		swap_point(&p0, &p1);
	dy = p1->y - p0->y;
	if ((uint32_t)p0->x >= WIDTH || (uint32_t)p0->y >= HEIGHT
		|| (uint32_t)p1->x >= WIDTH || (uint32_t)p1->y >= HEIGHT)
		return ;
	mlx_put_pixel(img, (int)p0->x, (int)p0->y, p0->color);
	if ((int)(p1->x - p0->x) > abs(dy))
	{
		if (dy > 0)
			drawline_low_up(img, *p0, *p1);
		else
			drawline_low_down(img, *p0, *p1);
	}
	else
	{
		if (dy > 0)
			drawline_high_up(img, *p0, *p1);
		else
			drawline_high_down(img, *p0, *p1);
	}
	mlx_put_pixel(img, (int)p1->x, (int)p1->y, p1->color);
}
void	drawline_low_down(mlx_image_t *img, t_point p0, t_point p1)
{
	int		dx;
	int		dy;
	int		diff;
	int		x0;
	int		y0;
	x0 = p0.x;
	y0 = p0.y;
	dx = (int)p1.x - (int)p0.x;
	dy = (int)p0.y - (int)p1.y;
	diff = 2 * dy - dx;
	while (++x0 < (int)p1.x)
	{
		mlx_put_pixel(img, x0, y0, p0.color);
		if (diff > 0)
		{
			diff -= dx;
			--y0;
		}
		diff += dy;
	}
}
void	drawline_high_down(mlx_image_t *img, t_point p0, t_point p1)
{
	int		dx;
	int		dy;
	int		diff;
	int		x0;
	int		y0;
	x0 = p0.x;
	y0 = p0.y;
	dx = (int)p1.x - (int)p0.x;
	dy = (int)p0.y - (int)p1.y;
	diff = 2 * dx - dy;
	while (--y0 > (int)p1.y)
	{
		mlx_put_pixel(img, x0, y0, p0.color);
		if (diff > 0)
		{
			diff -= dy;
			++x0;
		}
		diff += dx;
	}
}
void	drawline_low_up(mlx_image_t *img, t_point p0, t_point p1)
{
	int		dx;
	int		dy;
	int		diff;
	int		x0;
	int		y0;
	x0 = p0.x;
	y0 = p0.y;
	dx = (int)p1.x - (int)p0.x;
	dy = (int)p1.y - (int)p0.y;
	diff = 2 * dy - dx;
	while (++x0 < (int)p1.x)
	{
		mlx_put_pixel(img, x0, y0, p0.color);
		if (diff > 0)
		{
			diff -= dx;
			++y0;
		}
		diff += dy;
	}
}
void	drawline_high_up(mlx_image_t *img, t_point p0, t_point p1)
{
	int		dx;
	int		dy;
	int		diff;
	int		x0;
	int		y0;
	x0 = p0.x;
	y0 = p0.y;
	dx = (int)p1.x - (int)p0.x;
	dy = (int)p1.y - (int)p0.y;
	diff = 2 * dx - dy;
	while (++y0 < (int)p1.y)
	{
		mlx_put_pixel(img, x0, y0, p0.color);
		if (diff > 0)
		{
			diff -= dy;
			++x0;
		}
		diff += dx;
	}
}

void	swap_point(t_point **p0, t_point **p1)
{
	t_point	*temp;
	temp = *p0;
	*p0 = *p1;
	*p1 = temp;
}
