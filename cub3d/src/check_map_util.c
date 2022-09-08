/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:06:24 by soum              #+#    #+#             */
/*   Updated: 2022/09/07 17:32:18 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map(const char *read_line)
{
	while (*read_line == ' ')
		++read_line;
	if (ft_isdigit(*read_line))
		return (1);
	return (0);
}

int	is_map_line(char *read_line)
{
	if (read_line == NULL)
		return (0);
	while (*read_line && *read_line != '\n')
	{
		if (ft_strchr("013NSWE ", *read_line++))
			return (1);
	}
	return (0);
}
