/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:33:09 by soum              #+#    #+#             */
/*   Updated: 2022/06/04 23:12:09 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

inline void	pos_togrid(int *pos, int *grid)
{
	grid[0] = (pos[0] -1) / GRID;
	grid[1] = (pos[1] -1) / GRID;
}

uint32_t	to_le(uint32_t color)
{
	unsigned char	bytes[4];
	uint32_t		ret;

	bytes[0] = (unsigned char)((color >> 24) & 0xff);
	bytes[1] = (unsigned char)((color >> 16) & 0xff);
	bytes[2] = (unsigned char)((color >> 8) & 0xff);
	bytes[3] = (unsigned char)((color >> 0) & 0xff);
	ret = ((uint32_t)bytes[0] << 0) | \
		((uint32_t)bytes[1] << 8) | \
		((uint32_t)bytes[2] << 16) | \
		((uint32_t)bytes[3] << 24);
	return (ret);
}

void	memset_all_image(t_image *image)
{
	memset(image->bg_img->pixels, 90, image->bg_img->width * \
			image->bg_img->height * sizeof(int));
	memset(image->cub_img->pixels, 128, image->cub_img->width * \
			image->cub_img->height * sizeof(int));
}

inline int	is_invisible(uint32_t *color)
{
	unsigned char	byte;

	*color = to_le(*color);
	byte = *color & 0xff;
	if (!byte)
		return (1);
	return (0);
}
