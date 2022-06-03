/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:29:49 by soum              #+#    #+#             */
/*   Updated: 2022/05/31 16:07:46 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error_msg(char *msg, int error_num, t_mlx_data *data)
{
	if (error_num == 3)
		printf("%s check argument", msg);
	else if (error_num == 4)
		printf("%s (open)\n", msg);
	else if (error_num == 5)
	{
		printf("%s (malloc)\n", msg);
		free_map(data);
	}
	else if (error_num == PLAYER_ERROR)
	{
		printf("%s (no player)\n", msg);
		free_map(data);
	}
	exit(error_num);
}
