/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FreeData.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 23:21:51 by soum              #+#    #+#             */
/*   Updated: 2022/06/12 19:49:21 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	free_char(char **data)
{
	int	idx;

	idx = 0;
	if (!data)
		return (0);
	while (data[idx])
	{
		free(data[idx]);
		idx++;
	}
	free(data);
	return (1);
}

void	free_txt(t_mlx_data *data)
{
	t_texture	*txt;

	txt = &data->texture;
	if (txt->n_wall_path)
		free(txt->n_wall_path);
	if (txt->s_wall_path)
		free(txt->s_wall_path);
	if (txt->e_wall_path)
		free(txt->e_wall_path);
	if (txt->w_wall_path)
		free(txt->w_wall_path);
}

void	free_fc(t_mlx_data *data)
{
	char	**floor;
	char	**ceiling;

	floor = data->texture.floor_txt;
	ceiling = data->texture.ceiling_txt;
	free_char(floor);
	free_char(ceiling);
}

void	free_map(t_mlx_data *data)
{
	char	**map;

	map = data->map.map;
	free_char(map);
}

void	free_all_data(t_mlx_data *data, int error_idx)
{
	if (error_idx & 0b100)
		free_fc(data);
	if (error_idx & 0b1000)
		free_txt(data);
	if (error_idx & 0b10000)
		free_map(data);
	if (error_idx == PRESS_ESC)
	{
		mlx_close_window(data->mlx);
		error_idx = 0;
	}
	exit(error_idx);
}
