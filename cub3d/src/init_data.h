/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:06:56 by soum              #+#    #+#             */
/*   Updated: 2022/09/04 15:06:56 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_DATA_H
# define INIT_DATA_H

# include <stdio.h>
# include <math.h>

# include "cub3d.h"
# include "read_config.h"
# include "minimap.h"
# include "error.h"
# include "sprite.h"
# include "get_next_line.h"
# include "garbage_collector/garbage_collector.h"

# define RESIZABLE (0)

int		init_data(int argc, char **argv, t_mlx_data *mlx_data);
void	init_map(const char *path, t_mlx_data *mlx_data);
int		get_map_line(const char *path);
int		jump_to_map(const char *path, int map_line_num);
int		check_map_validity(uint32_t **map, int rows, int cols,
			t_ivec2 *player_pos);

#endif
