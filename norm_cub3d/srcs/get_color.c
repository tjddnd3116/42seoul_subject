/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:25:11 by soum              #+#    #+#             */
/*   Updated: 2022/06/03 18:19:12 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

uint32_t	get_player_color(mlx_texture_t *p_txt, t_player *p, int *xy)
{
	uint32_t color;
	int		addr;

	addr = (xy[0] * p_txt->width / p->scale_size[0]) + \
		   ((xy[1] * p_txt->height / p->scale_size[1]) * p_txt->width);
	color = *((uint32_t *)p_txt->pixels + addr);
	return (color);
}
