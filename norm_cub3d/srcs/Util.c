/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:33:09 by soum              #+#    #+#             */
/*   Updated: 2022/06/08 00:07:35 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <string.h>

void	*ft_memset2(void *b, uint32_t c, uint32_t d, size_t len);

void	get_frametime(void)
{
	static int		frame;
	static clock_t	past;
	static clock_t	now;
	float			frametime;

	now = clock();
	frametime = (float)(now - past) / CLOCKS_PER_SEC;
	past = now;
	printf("fps = %6.2f  frametime = %6.4f\n",
		1 / frametime, frametime);
	++frame;
}

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

void	memset_all_image(t_image *image , t_texture *txt)
{
	/** size_t		tmp; */

	(void)txt;
	/** uint32_t	floor_color; */
	/** uint32_t	ciling_color; */
    /**  */
	/** floor_color = txt->floor_color; */
	/** ciling_color = txt->ceiling_color; */
	/** tmp = (image->cub_img->width * (image->cub_img->height - 1)); */
	ft_memset(image->minimap_img->pixels, 0x00000000, \
			image->minimap_img->width * \
			image->minimap_img->height * sizeof(int));
	/** ft_memset2(image->cub_img->pixels, floor_color, ciling_color, tmp * (sizeof(int32_t))); */
	/** ft_memset2(image->cub_img->pixels + (tmp * 4), floor_color, tmp); */

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
void	*ft_memset2(void *b, uint32_t c, uint32_t d, size_t len)
{
	uint8_t		*tmp;
	size_t		index;
	uint32_t	tmp_c;
	uint32_t	tmp_d;


	index = 0;
	tmp = b;
	while (index < len / 2)
	{
		tmp_c = c;
		*(tmp++) = (uint8_t)(c >> 24);
		*(tmp++) = (uint8_t)(c >> 16);
		*(tmp++) = (uint8_t)(c >> 8);
		*(tmp++) = (uint8_t)(c & 0xFF);
	}
	while (index < len)
	{
		tmp_d = d;
		*(tmp++) = (uint8_t)(d >> 24);
		*(tmp++) = (uint8_t)(d >> 16);
		*(tmp++) = (uint8_t)(d >> 8);
		*(tmp++) = (uint8_t)(d & 0xFF);
	}
	return (b);
}
