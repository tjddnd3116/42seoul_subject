/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:07:27 by soum              #+#    #+#             */
/*   Updated: 2022/09/04 15:07:27 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "user_interface.h"

void	user_interface(t_mlx_data *mlx_data)
{
	crosshair_line(mlx_data, 6, 6);
}

void	print_frame(void)
{
	struct timeval	time1;
	static uint64_t	old_ms;
	uint64_t		ms;

	gettimeofday(&time1, NULL);
	ms = time1.tv_sec * 1000 + time1.tv_usec / 1000;
	printf("fps: %f\n", 1000.0 / (ms - old_ms));
	old_ms = ms;
}

void	crosshair_line(t_mlx_data *data, int pos, int len)
{
	int			idx;
	mlx_image_t	*img;

	idx = 0;
	img = data->main_img;
	while (idx < len)
	{
		mlx_put_pixel(img, (img->width >> 1) + pos + idx,
			img->height >> 1, 0x3fbf1fff);
		mlx_put_pixel(img, (img->width >> 1) + pos + idx + 1,
			(img->height >> 1) + 1, 0x000000ff);
		mlx_put_pixel(img, (img->width >> 1) - pos - idx,
			img->height >> 1, 0x3fbf1fff);
		mlx_put_pixel(img, (img->width >> 1) - pos - idx + 1,
			(img->height >> 1) + 1, 0x000000ff);
		mlx_put_pixel(img, img->width >> 1,
			(img->height >> 1) + pos + idx, 0x3fbf1fff);
		mlx_put_pixel(img, (img->width >> 1) + 1,
			(img->height >> 1) + pos + idx + 1, 0x000000ff);
		mlx_put_pixel(img, img->width >> 1,
			(img->height >> 1) - pos - idx, 0x3fbf1fff);
		mlx_put_pixel(img, (img->width >> 1) + 1,
			(img->height >> 1) - pos - idx + 1, 0x000000ff);
		++idx;
	}
}
