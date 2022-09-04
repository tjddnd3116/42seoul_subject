/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:07:08 by soum              #+#    #+#             */
/*   Updated: 2022/09/04 15:07:08 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_MOVE_H
# define PLAYER_MOVE_H

# include <math.h>

# include "cub3d.h"

# define PLAYER_SIZE (128)

int	player_move(t_player *player, double move_x, double move_y,
		t_mlx_data *data);

#endif
