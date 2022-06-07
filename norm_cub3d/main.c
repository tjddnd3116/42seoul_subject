/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:20:07 by soum              #+#    #+#             */
/*   Updated: 2022/06/07 23:37:53 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "includes/cub3d.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_mlx_data	data;

	if (argc != 2)
		error_msg("arg error", ARG_ERROR, &data);
	init_data(&data, argv[1]);
	memset_all_image(&data.image, &data.texture);
	put_pixels(&data);
	mlx_image_to_window(data.mlx, data.image.cub_img, 0, 0);
	mlx_image_to_window(data.mlx, data.image.minimap_img, 0, 0);
	mlx_loop_hook(data.mlx, my_hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (0);
}
