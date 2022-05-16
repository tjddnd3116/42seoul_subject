/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: W2Wizard <w2.wizzard@gmail.com>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/31 00:40:08 by W2Wizard      #+#    #+#                 */
/*   Updated: 2022/05/16 23:17:12 by soum             ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <math.h>
#define WIDTH 128*8
#define HEIGHT 128*8
int map[]=           //the map array. Edit to change level but keep the outer walls
{
 1,1,1,1,1,1,1,1,
 1,0,1,0,0,0,0,1,
 1,0,1,0,0,0,0,1,
 1,0,1,0,0,0,0,1,
 1,0,0,0,0,0,0,1,
 1,0,0,0,0,1,0,1,
 1,0,0,0,0,0,0,1,
 1,1,1,1,1,1,1,1,
};

mlx_image_t	*g_img;
mlx_image_t *g_bg_black;
mlx_image_t *g_bg_white;
mlx_image_t *g_ray;

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
	if (mlx_is_key_down(param, MLX_KEY_UP))
	{
		g_img->instances[0].y -= 5;
		g_ray->instances[0].y -= 5;
	}
	if (mlx_is_key_down(param, MLX_KEY_DOWN))
	{
		g_img->instances[0].y += 5;
		g_ray->instances[0].y += 5;

	}
	if (mlx_is_key_down(param, MLX_KEY_LEFT))
	{
		g_img->instances[0].x -= 5;
		g_ray->instances[0].x -= 5;
	}
	if (mlx_is_key_down(param, MLX_KEY_RIGHT))
	{
		g_img->instances[0].x += 5;
		g_ray->instances[0].x += 5;
	}
}
void background_image(mlx_t *mlx)
{
	int x = 0;
	int y = 0;
	int cnt = 0;
	for (int i = 0; i < 64; i++)
	{
		if (cnt == 8)
		{
			x = 0;
			y+= 128;
			cnt = 0;
		}
		if (map[i] == 1)
			mlx_image_to_window(mlx, g_bg_black, x, y);
		else
			mlx_image_to_window(mlx, g_bg_white, x, y);
		x += 128;
		cnt++;
	}
}

int32_t	main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, 64, 64);
	g_bg_black = mlx_new_image(mlx,128,128);
	g_bg_white = mlx_new_image(mlx,128,128);
	g_ray = mlx_new_image(mlx,10,10);
	memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	memset(g_bg_black->pixels, 189, g_bg_black->width * g_bg_black->height * sizeof(int));
	memset(g_bg_white->pixels, 128, g_bg_white->width * g_bg_white->height * sizeof(int));
	memset(g_ray->pixels, 255, g_ray->width * g_ray->height * sizeof(int));

	mlx_image_to_window(mlx, g_img, 0, 0);
	mlx_image_to_window(mlx, g_ray, 65, 64);
	background_image(mlx);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
