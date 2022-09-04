/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:06:05 by soum              #+#    #+#             */
/*   Updated: 2022/09/04 15:07:12 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include <math.h>
# include <stdio.h>

# include "cub3d.h"
# include "player_move.h"
# include "minimap.h"

# define INF_GUARD (0.015)
# define FOG_FACTOR (800)

# define HALF_GRID_LEN (256)

static const double		g_fov = M_PI / 3;
static const int32_t	g_half_screen_height = SCREEN_HEIGHT / 2;
static const int32_t	g_canvas_dist = 4 * PLAYER_SIZE;
static const int32_t	g_ray_cnt = SCREEN_WIDTH / 2;
static const double		g_ray_to_pixel = (double)SCREEN_WIDTH / g_ray_cnt;

typedef t_player		t_camera;

t_ray		detect_wall(t_camera ray, t_map map);
int			map_type_check(t_ray *ray, t_map *map, double angle);
double		get_distance(t_ray ray, t_camera camera);
int			boundary_check(t_ray ray, t_map map);

int32_t		get_pos(mlx_texture_t *texture, t_ray *point, uint32_t type);
uint32_t	apply_fog_bswap(uint32_t color, double fog);
uint32_t	apply_fog(uint32_t color, double fog);

#endif
