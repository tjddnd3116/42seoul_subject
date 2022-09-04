/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:06:38 by soum              #+#    #+#             */
/*   Updated: 2022/09/04 15:06:38 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "error.h"

static const char	*g_error_msg_list[] = {
	"invalid argument",
	"filename error",
	"file open error",
	"config format error",
	"config file has duplicate option",
	"there is not enough options",
	"invalid rgb value of floor or ceiling",
	"invalid texture path or name",
	"can not find map",
	"invalid map",
	"memory allocation error",
	"mlx initializaion failed",
	"mlx new image failed",
	"mlx image to window error",
};

void	error_handler(int status)
{
	if (status == 0)
		return ;
	ft_putendl_fd(g_error_msg_list[status - 1], STDERR_FILENO);
	dump_garbage();
	exit(status);
}
//	system("leaks cub3d");
