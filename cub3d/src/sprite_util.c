/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:07:25 by soum              #+#    #+#             */
/*   Updated: 2022/09/04 15:07:26 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "sprite.h"

uint32_t	get_sprite_color(t_sprite *sprite, int32_t pos, int32_t y)
{
	mlx_texture_t	*texture;
	uint32_t		color;
	int32_t			range;

	texture = sprite->texture[sprite->idx];
	range = g_canvas_dist * g_half_screen_height / sprite->distance;
	if (-range + g_half_screen_height > y || range + g_half_screen_height <= y)
		return (0);
	y = (y - g_half_screen_height + range) * texture->height / (2 * range);
	color = *((uint32_t *)texture->pixels + \
			((int)y * texture->width + pos));
	color = apply_fog_bswap(color, FOG_FACTOR
			/ (sprite->distance + FOG_FACTOR));
	return (color);
}

int	compare(const void *comp1, const void *comp2)
{
	if (((t_sprite *)comp1)->distance < ((t_sprite *)comp2)->distance)
		return (1);
	return (-1);
}
