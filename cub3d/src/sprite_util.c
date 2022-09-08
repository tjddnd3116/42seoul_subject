/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:07:25 by soum              #+#    #+#             */
/*   Updated: 2022/09/07 17:55:03 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"
#include "screen_renderer.h"

uint32_t	get_sprite_color(t_col_line_info *info, int32_t y)
{
	if (-info->range + g_half_screen_height > y
		|| info->range + g_half_screen_height <= y)
		return (0);
	y = (y - g_half_screen_height + info->range)
		* info->texture->height / (2 * info->range);
	return (apply_fog_bswap(*((uint32_t *)info->texture->pixels + \
			((int)y * info->texture->width + info->pos)), info->fog_factor));
}

int	compare(const void *comp1, const void *comp2)
{
	if (((t_sprite *)comp1)->distance < ((t_sprite *)comp2)->distance)
		return (1);
	return (-1);
}
