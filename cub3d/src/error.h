/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:06:40 by soum              #+#    #+#             */
/*   Updated: 2022/09/04 15:06:40 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "cub3d.h"
# include "garbage_collector/garbage_collector.h"

enum e_error_status
{
	NONE,
	ARGUMENT_ERROR,
	FILENAME_ERROR,
	FILE_OPEN_ERROR,
	CONFIG_FORMAT_ERROR,
	CONFIG_DUPLICATE_ERROR,
	CONFIG_NOT_ENOUGH_OPTION_ERROR,
	CONFIG_INVALID_RGB_ERROR,
	TEXTURE_LOAD_ERROR,
	MAP_FIND_ERROR,
	MAP_INVALID_ERROR,
	MALLOC_ERROR,
	MLX_INIT_ERROR,
	MLX_IMG_ERROR,
	MLX_IMG_TO_WIN_ERROR,
};

void	error_handler(int status);

#endif
