/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InitData.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:20:58 by soum              #+#    #+#             */
/*   Updated: 2022/05/28 22:57:50 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_data(t_mlx_data *data, char *map_path)
{
	int	is_error;

	is_error = init_map(&data->map, map_path);
	if (is_error)
		error_msg("map error");
}
