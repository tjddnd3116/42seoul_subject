/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_renderer.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:07:22 by soum              #+#    #+#             */
/*   Updated: 2022/09/04 15:07:22 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_RENDERER_H
# define SCREEN_RENDERER_H

# include <stdio.h>
# include <math.h>

# include "cub3d.h"
# include "raycasting.h"
# include "hook.h"
# include "minimap.h"
# include "drawline.h"
# include "user_interface.h"
# include "sprite.h"
# include "gun.h"

# define MINIMAP_RAY_NUM (1)

typedef struct s_col_line_info
{
	mlx_texture_t	*wall_texture;
	int32_t			range;
	int32_t			pos;
	double			fog;
	double			fog_factor;
}	t_col_line_info;

void	screen_renderer(void *data);
void	draw_col_line(t_mlx_data *data, t_ray point, int idx);

#endif
