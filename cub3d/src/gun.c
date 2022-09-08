/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:06:49 by soum              #+#    #+#             */
/*   Updated: 2022/09/07 17:39:58 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gun.h"

int	gun_image_to_window(t_mlx_data *mlx_data, int gun_idx)
{
	uint32_t		xy[2];
	uint32_t		wh[2];
	mlx_texture_t	*gun_texture;

	gun_texture = mlx_data->texture_list.gun[gun_idx];
	xy[0] = 0;
	xy[1] = 0;
	wh[0] = gun_texture->width;
	wh[1] = gun_texture->height;
	if (mlx_data->gun_img)
		mlx_delete_image(mlx_data->mlx_ptr, mlx_data->gun_img);
	mlx_data->gun_img
		= mlx_texture_area_to_image(mlx_data->mlx_ptr, gun_texture, xy, wh);
	return (mlx_image_to_window(mlx_data->mlx_ptr, mlx_data->gun_img,
			SCREEN_WIDTH / 2 - wh[0] / 2,
			SCREEN_HEIGHT - wh[1] - gun_idx * 10));
}

int	ammo_string_to_window(t_mlx_data *mlx_data, char *ammo_num)
{
	if (mlx_data->ammo_img)
		mlx_delete_image(mlx_data->mlx_ptr, mlx_data->ammo_img);
	mlx_data->ammo_img = mlx_put_string(mlx_data->mlx_ptr,
			ammo_num, SCREEN_WIDTH / 2 + 10, SCREEN_HEIGHT / 2);
	if (mlx_data->ammo_img == NULL)
		return (-1);
	return (1);
}

void	get_ammo(t_mlx_data *mlx_data)
{
	t_player	player;
	t_map		*map;
	uint32_t	*type;

	player = mlx_data->player;
	map = &mlx_data->map;
	type = &map->map[player.grid.y][player.grid.x];
	if (((*type & SPECIAL_TYPE_BITMASK) == MAP_SPRITE_NONBLOCK)
		&& ((*type >> INFO_BITSHIFT) == 3))
	{
		gun_event(mlx_data, 1);
		*type = MAP_EMPTY;
	}
}

int	gun_event(t_mlx_data *mlx_data, int get_ammo)
{
	static int	idx;
	static char	ammo[2] = "9";

	if (get_ammo)
	{
		ammo[0] = '9';
		ammo_string_to_window(mlx_data, "10");
		return (0);
	}
	if (ammo[0] == '0' - 1)
		return (0);
	idx++;
	if (idx == 15)
	{
		enemy_got_shot(mlx_data);
		gun_image_to_window(mlx_data, 0);
		ammo_string_to_window(mlx_data, ammo);
		ammo[0]--;
		idx = 0;
		return (0);
	}
	else if (idx % 5 == 0)
		gun_image_to_window(mlx_data, idx / 5);
	return (1);
}
