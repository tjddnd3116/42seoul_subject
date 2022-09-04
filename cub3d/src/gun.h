/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:06:50 by soum              #+#    #+#             */
/*   Updated: 2022/09/04 15:55:04 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUN_H
# define GUN_H

# include "cub3d.h"
# include "sprite.h"

int		gun_image_to_window(t_mlx_data *mlx_data, int gun_idx);
int		ammo_string_to_window(t_mlx_data *mlx_data, char *ammo_num);
void	get_ammo(t_mlx_data *mlx_data);
int		gun_event(t_mlx_data *mlx_data, int get_ammo);

#endif
