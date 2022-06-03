/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FreeData.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 23:21:51 by soum              #+#    #+#             */
/*   Updated: 2022/05/29 14:52:13 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_map(t_mlx_data *data)
{
	int		idx;

	idx = 0;
	while (data->map->map[idx])
		free(data->map->map[idx++]);
	free(data->map->map);
	free(data->map);
}
