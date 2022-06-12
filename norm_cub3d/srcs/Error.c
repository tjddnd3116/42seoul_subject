/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:29:49 by soum              #+#    #+#             */
/*   Updated: 2022/06/12 19:43:42 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error_msg(char *msg, int error_idx, t_mlx_data *data)
{
	printf("%s\n", msg);
	free_all_data(data, error_idx);
}
