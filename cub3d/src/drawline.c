/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:35:23 by hseong            #+#    #+#             */
/*   Updated: 2022/09/04 15:06:32 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawline.h"

typedef void					(*t_drawline_func)(mlx_image_t *,
		t_vec2, t_vec2);

static void	drawline_low_up(mlx_image_t *minimap, t_vec2 p0, t_vec2 p1);
static void	drawline_low_down(mlx_image_t *minimap, t_vec2 p0, t_vec2 p1);
static void	drawline_high_up(mlx_image_t *minimap, t_vec2 p0, t_vec2 p1);
static void	drawline_high_down(mlx_image_t *minimap, t_vec2 p0, t_vec2 p1);

static const uint32_t			g_color = 0xff0f0fff;
static const t_drawline_func	g_drawline_tab[4] = {
	drawline_low_down,
	drawline_low_up,
	drawline_high_down,
	drawline_high_up
};

void	drawline(mlx_image_t *minimap, t_vec2 p0, t_vec2 p1)
{
	int		dy;

	if ((int)(p1.x - p0.x) < 0)
		swap_point(&p0, &p1);
	dy = p1.y - p0.y;
	if ((uint32_t)p0.x >= MINIMAP_WIDTH || (uint32_t)p0.y >= MINIMAP_HEIGHT
		|| (uint32_t)p1.x >= MINIMAP_WIDTH || (uint32_t)p1.y >= MINIMAP_HEIGHT)
		return ;
	*((uint32_t *)minimap->pixels + (int)p0.x + minimap->width * (int)p0.y)
		= g_color;
	if ((int)(p1.x - p0.x) > ft_abs(dy))
		g_drawline_tab[dy > 0](minimap, p0, p1);
	else
		g_drawline_tab[(dy > 0) + 2](minimap, p0, p1);
	*((uint32_t *)minimap->pixels + (int)p1.x + minimap->width * (int)p1.y)
		= g_color;
}

void	drawline_low_down(mlx_image_t *minimap, t_vec2 p0, t_vec2 p1)
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
		*((uint32_t *)minimap->pixels + x0 + minimap->width * y0) = g_color;
		if (diff > 0)
		{
			diff -= dx;
			--y0;
		}
		diff += dy;
	}
}

void	drawline_high_down(mlx_image_t *minimap, t_vec2 p0, t_vec2 p1)
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
		*((uint32_t *)minimap->pixels + x0 + minimap->width * y0) = g_color;
		if (diff > 0)
		{
			diff -= dy;
			++x0;
		}
		diff += dx;
	}
}

void	drawline_low_up(mlx_image_t *minimap, t_vec2 p0, t_vec2 p1)
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
		*((uint32_t *)minimap->pixels + x0 + minimap->width * y0) = g_color;
		if (diff > 0)
		{
			diff -= dx;
			++y0;
		}
		diff += dy;
	}
}

void	drawline_high_up(mlx_image_t *minimap, t_vec2 p0, t_vec2 p1)
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
		*((uint32_t *)minimap->pixels + x0 + minimap->width * y0) = g_color;
		if (diff > 0)
		{
			diff -= dy;
			++x0;
		}
		diff += dx;
	}
}
