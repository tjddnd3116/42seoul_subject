/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:03:24 by soum              #+#    #+#             */
/*   Updated: 2021/11/01 16:24:31 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	rendering(t_window *window)
{
	mlx_put_image_to_window(window->mlx, window->win, window->img.img, 0, 0);
	return (1);
}

int	is_background_color(t_obj *obj, char *color)
{
	unsigned int	temp_color;
	int				obj_color;
	int				background;

	background = 0x99CCFF;
	if (obj == NULL)
		return (background);
	temp_color = *(unsigned int *)(obj->addr);
	obj_color = *(int *)color;
	if (obj_color == temp_color)
		return (background);
	else
		return (obj_color);
}
