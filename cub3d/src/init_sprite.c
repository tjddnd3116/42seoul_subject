/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:07:00 by soum              #+#    #+#             */
/*   Updated: 2022/09/04 15:17:16 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "dlinkedlist.h"
#include "raycasting.h"
#include "player_move.h"
#include "sprite.h"

void	init_item_sprite(t_mlx_data *mlx_data, uint32_t type, t_sprite *sprite);
void	init_gun_sprite(t_mlx_data *mlx_data, uint32_t type, t_sprite *sprite);
void	init_enemy_sprite(t_mlx_data *mlx_data, uint32_t type,
			t_sprite *sprite);
void	push_sprite(t_mlx_data *mlx_data, int idx, int jdx, uint32_t type);

void	init_sprite(t_mlx_data *mlx_data)
{
	int				idx;
	int				jdx;
	uint32_t		type;

	idx = 0;
	while (idx < mlx_data->map.height)
	{
		jdx = 0;
		while (jdx < mlx_data->map.width)
		{
			type = mlx_data->map.map[idx][jdx];
			if ((type & SPECIAL_TYPE_BITMASK) == MAP_SPRITE_NONBLOCK)
				push_sprite(mlx_data, idx, jdx, type >> INFO_BITSHIFT);
			jdx++;
		}
		idx++;
	}
}

void	push_sprite(t_mlx_data *mlx_data, int idx, int jdx, uint32_t type)
{
	t_sprite		*sprite;

	sprite = malloc(sizeof(t_sprite));
	sprite->type = &mlx_data->map.map[idx][jdx];
	if (type < 4)
		init_item_sprite(mlx_data, type, sprite);
	else if (type == 4)
		init_enemy_sprite(mlx_data, type, sprite);
	sprite->x = jdx * GRID_LEN + GRID_LEN / 2.0;
	sprite->y = idx * GRID_LEN + GRID_LEN / 2.0;
	push_back(&mlx_data->sprite_list, sprite);
}

void	init_sprite_texture(t_mlx_data *mlx_data)
{
	mlx_data->texture_list.barrel = mlx_load_png(BARREL_SPRITE_TEXTURE);
	mlx_data->texture_list.light = mlx_load_png(LIGHT_SPRITE_TEXTURE);
	mlx_data->texture_list.ammo = mlx_load_png(AMMO_SPRITE_TEXTURE);
	mlx_data->texture_list.gun[0] = mlx_load_png(GUN_SPRITE_TEXTURE_1);
	mlx_data->texture_list.gun[1] = mlx_load_png(GUN_SPRITE_TEXTURE_2);
	mlx_data->texture_list.gun[2] = mlx_load_png(GUN_SPRITE_TEXTURE_3);
	mlx_data->texture_list.enemy[0] = mlx_load_png(ENEMY_SPRITE_TEXTURE_1);
	mlx_data->texture_list.enemy[1] = mlx_load_png(ENEMY_SPRITE_TEXTURE_2);
	mlx_data->texture_list.enemy[2] = mlx_load_png(ENEMY_SPRITE_TEXTURE_3);
	mlx_data->texture_list.enemy[3] = mlx_load_png(ENEMY_SPRITE_TEXTURE_4);
	mlx_data->texture_list.enemy[4] = mlx_load_png(ENEMY_SPRITE_TEXTURE_5);
	mlx_data->texture_list.enemy[5] = mlx_load_png(ENEMY_SPRITE_TEXTURE_6);
	mlx_data->texture_list.enemy[6] = mlx_load_png(ENEMY_SPRITE_TEXTURE_7);
	mlx_data->texture_list.enemy[7] = mlx_load_png(ENEMY_SPRITE_TEXTURE_8);
}

void	init_item_sprite(t_mlx_data *mlx_data, uint32_t type, t_sprite *sprite)
{
	sprite->texture = malloc(sizeof(mlx_texture_t));
	if (type == 1)
		sprite->texture[0] = mlx_data->texture_list.barrel;
	else if (type == 2)
		sprite->texture[0] = mlx_data->texture_list.light;
	else if (type == 3)
		sprite->texture[0] = mlx_data->texture_list.ammo;
	sprite->idx = 0;
	sprite->size = 1;
}

void	init_enemy_sprite(t_mlx_data *mlx_data, uint32_t type, t_sprite *sprite)
{
	(void)type;
	sprite->texture = malloc(sizeof(mlx_texture_t) * 8);
	sprite->texture[0] = mlx_data->texture_list.enemy[0];
	sprite->texture[1] = mlx_data->texture_list.enemy[1];
	sprite->texture[2] = mlx_data->texture_list.enemy[2];
	sprite->texture[3] = mlx_data->texture_list.enemy[3];
	sprite->texture[4] = mlx_data->texture_list.enemy[4];
	sprite->texture[5] = mlx_data->texture_list.enemy[5];
	sprite->texture[6] = mlx_data->texture_list.enemy[6];
	sprite->texture[7] = mlx_data->texture_list.enemy[7];
	sprite->idx = 0;
	sprite->size = 8;
}
