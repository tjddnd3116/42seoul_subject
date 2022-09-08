/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:06:41 by soum              #+#    #+#             */
/*   Updated: 2022/09/07 18:05:50 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

void	esc_exit(t_mlx_data *mlx_data)
{
	mlx_close_window(mlx_data->mlx_ptr);
	mlx_terminate(mlx_data->mlx_ptr);
	dump_garbage();
	exit(0);
}
