/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 00:02:04 by soum              #+#    #+#             */
/*   Updated: 2021/11/01 16:22:50 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

char	*get_obj_color(t_obj *obj, int cube_x, int cube_y, int cube_size)
{
	int		obj_x;
	int		obj_y;
	char	*color;

	obj_x = (obj->width * cube_x) / cube_size;
	obj_y = (obj->height * cube_y) / cube_size;
	color = obj->addr + (obj_y * obj->line_len + obj_x * (obj->bpp / 8));
	return (color);
}

t_obj	*what_obj(t_window *window, char pos)
{
	if (pos == 'P')
		return (&window->obj_player);
	if (pos == 'E')
		return (&window->obj_exit);
	if (pos == 'C')
		return (&window->obj_item);
	if (pos == '1')
		return (&window->obj_wall);
	if (pos == '0')
		return (NULL);
	return (NULL);
}

void	render_cube(t_window *window, int map_x, int map_y)
{
	t_obj	*obj;
	int		cube_x;
	int		cube_y;
	char	*color;

	obj = what_obj(window, window->map[map_y][map_x]);
	cube_y = -1;
	while (++cube_y < window->cube_size)
	{
		cube_x = -1;
		while (++cube_x < window->cube_size)
		{
			color = "";
			if (obj != NULL)
				color = get_obj_color(obj, cube_x, cube_y, window->cube_size);
			if (color != NULL)
				my_mlx_pixel_put(&window->img, \
						(map_x * window->cube_size) + cube_x, \
						(map_y * window->cube_size) + cube_y, \
						is_background_color(obj, color));
		}
	}
}

void	render_image(t_window *window)
{
	int	map_x;
	int	map_y;

	map_y = -1;
	while (++map_y < window->map_y)
	{
		map_x = -1;
		while (++map_x < window->map_x)
		{
			render_cube(window, map_x, map_y);
		}
	}
}
