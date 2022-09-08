/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:07:04 by soum              #+#    #+#             */
/*   Updated: 2022/09/07 17:43:34 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include <math.h>

# include "cub3d.h"

# define MINIMAP_WIDTH (384)
# define MINIMAP_HEIGHT (384)
# define MINIMAP_GRID_LEN (32)
# define MINIMAP_GRID_NUM (12)

# define MINIMAP_PLAYER_SIZE (8)
# define PLAYER_COLOR (0xff0f0fff)

void	render_minimap(const t_mlx_data data);

#endif
