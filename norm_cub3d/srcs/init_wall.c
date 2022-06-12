/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:25:35 by soum              #+#    #+#             */
/*   Updated: 2022/06/12 19:24:42 by soum             ###   ########.fr       */
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

void	load_wall_txt(t_mlx_data *data, int idx, char *read_line, int fd)
{
	char		*path;
	int			str_len;
	t_texture	*text;

	text = &data->texture;
	str_len = ft_strlen(read_line);
	path = ft_substr(read_line, 3, str_len - 4);
	if (idx == 1 && !text->n_wall_path)
		text->n_wall_path = path;
	else if (idx == 2 && !text->s_wall_path)
		text->s_wall_path = path;
	else if (idx == 3 && !text->w_wall_path)
		text->w_wall_path = path;
	else if (idx == 4 && !text->e_wall_path)
		text->e_wall_path = path;
	else
	{
		free(read_line);
		free(path);
		close(fd);
		error_msg("check cub file (wall texture)", TXT_INIT_ERROR, data);
	}
}

int	find_txt(t_mlx_data *data, char *read_line, int fd)
{
	int	str_len;

	str_len = ft_strlen(read_line);
	if (ft_strnstr(read_line, "NO", str_len))
		load_wall_txt(data, 1, read_line, fd);
	else if (ft_strnstr(read_line, "SO", str_len))
		load_wall_txt(data, 2, read_line, fd);
	else if (ft_strnstr(read_line, "WE", str_len))
		load_wall_txt(data, 3, read_line, fd);
	else if (ft_strnstr(read_line, "EA", str_len))
		load_wall_txt(data, 4, read_line, fd);
	else
	{
		free(read_line);
		close(fd);
		error_msg("check cub file (wall texture)", TXT_INIT_ERROR, data);
	}
	return (0);
}

int	check_wall_txt(t_mlx_data *data, int fd)
{
	char	*read_line;
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
			find_txt(data, read_line, fd);
		free(read_line);
	}
	free(read_line);
	close(fd);
	return (0);
}

int	init_wall_txt(t_mlx_data *data)
{
	t_texture	*wall_txt;
	t_map		*map_data;
	int			fd;

	map_data = &data->map;
	wall_txt = &data->texture;
	wall_txt->n_wall_path = NULL;
	wall_txt->s_wall_path = NULL;
	wall_txt->e_wall_path = NULL;
	wall_txt->w_wall_path = NULL;
	fd = jump_txt(map_data->map_path);
	if (fd < 0)
		error_msg("file open error", TXT_INIT_ERROR, data);
	check_wall_txt(data, fd);
	if (!wall_txt->n_wall_path || !wall_txt->s_wall_path || \
			!wall_txt->e_wall_path || !wall_txt->w_wall_path)
		error_msg("check cub file (wall texture)", TXT_INIT_ERROR, data);
	return (0);
}
