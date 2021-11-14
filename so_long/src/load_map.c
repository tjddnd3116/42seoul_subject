/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:16:41 by soum              #+#    #+#             */
/*   Updated: 2021/11/01 16:22:48 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_pos(t_pos *pos, int x, int y)
{
	pos->x = x;
	pos->y = y;
}

void	load_map_x(char *line, t_window *window, int y)
{
	int	x;

	x = -1;
	while (line[++x] != '\n')
	{
		if (line[x] == 'P')
			load_pos(&window->player, x, y);
	}
	window->map[y] = malloc(sizeof(char) * window->map_x);
	if (window->map[y] == NULL)
	{
		free_all_map(window, --y);
		error_msg_exit("map load alloc error");
	}
	ft_strlcpy(window->map[y], line, window->map_x + 1);
}

void	load_map_y(int fd, t_window *window)
{
	int		y;
	char	*tmp;

	y = 0;
	window->map = malloc(sizeof(char *) * window->map_y);
	if (window->map == NULL)
		error_msg_exit("map load alloc error");
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		load_map_x(tmp, window, y);
		y++;
		free(tmp);
	}
}

void	load_map(char *ber, t_window *window)
{
	int		fd;
	char	*tmp;

	fd = open(ber, O_RDONLY);
	load_map_y(fd, window);
}
