/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:25:35 by soum              #+#    #+#             */
/*   Updated: 2022/06/07 20:37:23 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	jump_txt(char *map_path)
{
	int		fd;
	char	*read_line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (fd);
	while (1)
	{
		read_line = get_next_line(fd);
		if (read_line[0] == '\n')
			break ;
		free(read_line);
	}
	free(read_line);
	return (fd);
}

void	load_wall_txt(t_texture *text, int idx, char *read_line, int str_len)
{
	char	*path;

	path = ft_substr(read_line, 3, str_len - 4);
	if (idx == 1)
		text->n_wall_path = path;
	else if (idx == 2)
		text->s_wall_path = path;
	else if (idx == 3)
		text->w_wall_path = path;
	else if (idx == 4)
		text->e_wall_path = path;
}

int	find_txt(char *read_line, t_texture *text)
{
	int	str_len;

	str_len = ft_strlen(read_line);
	if (ft_strnstr(read_line, "NO", str_len))
		load_wall_txt(text, 1, read_line, str_len);
	else if (ft_strnstr(read_line, "SO", str_len))
		load_wall_txt(text, 2, read_line, str_len);
	else if (ft_strnstr(read_line, "WE", str_len))
		load_wall_txt(text, 3, read_line, str_len);
	else if (ft_strnstr(read_line, "EA", str_len))
		load_wall_txt(text, 4, read_line, str_len);
	else
		return (CANT_FIND_TXT);
	return (0);
}

int	check_wall_txt(t_texture *text, int fd)
{
	char	*read_line;
	int		error;
	int		flag;

	flag = 1;
	while (1)
	{
		read_line = get_next_line(fd);
		if (!read_line)
			break ;
		if (read_line[0] == '\n')
			flag = 0;
		if (flag)
			error = find_txt(read_line, text);
		free(read_line);
	}
	free(read_line);
	close(fd);
	return (error);
}

int	init_wall_txt(t_mlx_data *data)
{
	int		error;
	t_map	*map_data;
	int		fd;

	map_data = &data->map;
	fd = jump_txt(map_data->map_path);
	if (fd < 0)
		return (MAP_OPEN_ERROR);
	error = check_wall_txt(&data->texture, fd);
	if (error)
		return (error);
	return (0);
}
