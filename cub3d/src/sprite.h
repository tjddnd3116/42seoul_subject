/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:07:24 by soum              #+#    #+#             */
/*   Updated: 2022/09/07 17:58:30 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include "cub3d.h"
# include "raycasting.h"
# include "player_move.h"

# define SPRITE_WIDTH (256)
# define MAX_SPRITE_TEXTURE (8)

# define LIGHT_SPRITE_TEXTURE ("./images/light.png")
# define BARREL_SPRITE_TEXTURE ("./images/barrel.png")
# define AMMO_SPRITE_TEXTURE ("./images/ammo.png")
# define GUN_SPRITE_TEXTURE_1 ("./images/gun1.png")
# define GUN_SPRITE_TEXTURE_2 ("./images/gun2.png")
# define GUN_SPRITE_TEXTURE_3 ("./images/gun3.png")
# define ENEMY_SPRITE_TEXTURE_1 ("./images/enemy1.png")
# define ENEMY_SPRITE_TEXTURE_2 ("./images/enemy2.png")
# define ENEMY_SPRITE_TEXTURE_3 ("./images/enemy3.png")
# define ENEMY_SPRITE_TEXTURE_4 ("./images/enemy4.png")
# define ENEMY_SPRITE_TEXTURE_5 ("./images/enemy5.png")
# define ENEMY_SPRITE_TEXTURE_6 ("./images/enemy6.png")
# define ENEMY_SPRITE_TEXTURE_7 ("./images/enemy7.png")
# define ENEMY_SPRITE_TEXTURE_8 ("./images/enemy8.png")

typedef struct s_sprite
{
	mlx_texture_t	**texture;
	int				size;
	int				idx;
	double			x;
	double			y;
	double			distance;
	uint32_t		*type;
}	t_sprite;

void		render_sprite(t_mlx_data *mlx_data, const double *depth_buffer);
uint32_t	get_sprite_color(t_col_line_info *info, int32_t y);
int			compare(const void *comp1, const void *comp2);
void		init_sprite_texture(t_mlx_data *mlx_data);
void		init_sprite(t_mlx_data *mlx_data);
void		enemy_got_shot(t_mlx_data *mlx_data);

#endif
