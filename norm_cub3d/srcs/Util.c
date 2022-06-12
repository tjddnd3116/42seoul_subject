/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:33:09 by soum              #+#    #+#             */
/*   Updated: 2022/06/12 19:38:04 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

inline int	is_invisible(uint32_t *color)
{
	unsigned char	byte;

	*color = to_le(*color);
	byte = *color & 0xff;
	if (!byte)
		return (1);
	return (0);
}
