/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:20:07 by soum              #+#    #+#             */
/*   Updated: 2022/06/13 15:27:59 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_mlx_data	data;

	if (argc != 2)
		error_msg("arg error : ./cub3d [cub file path]", ARG_ERROR, &data);
	init_data(&data, argv[1]);
	put_pixels(&data);
	mlx_image_to_window(data.mlx, data.image.cub_img, 0, 0);
	mlx_put_string(data.mlx, "press [m] open minimap", 0, 0);
	mlx_image_to_window(data.mlx, data.image.minimap_img, 0, 0);
	mlx_loop_hook(data.mlx, my_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
