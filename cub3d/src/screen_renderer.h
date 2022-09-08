/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_renderer.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:07:22 by soum              #+#    #+#             */
/*   Updated: 2022/09/07 17:59:27 by hseong           ###   ########.fr       */
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

void	screen_renderer(void *data);
void	draw_col_line(t_mlx_data *data, t_ray point, int idx);

#endif
