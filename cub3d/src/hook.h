/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:06:53 by soum              #+#    #+#             */
/*   Updated: 2022/09/07 17:39:52 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include <math.h>

# include "cub3d.h"
# include "player_move.h"
# include "door.h"
# include "gun.h"
# include "exit.h"
# include "sprite.h"

# define SPEED (50)
# define ANGULAR_SPEED (0.06)
# define MOUSE_SENSITIVITY (0.001)

void	key_event(t_mlx_data *data);
void	cursor_event(t_mlx_data *data);

void	move_forward(t_mlx_data *mlx_data);
void	move_left(t_mlx_data *mlx_data);
void	move_backward(t_mlx_data *mlx_data);
void	move_right(t_mlx_data *mlx_data);

#endif
