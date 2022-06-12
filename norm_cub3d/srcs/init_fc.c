/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:09:29 by soum              #+#    #+#             */
/*   Updated: 2022/06/12 18:36:36 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

uint32_t	char_to_color(char **text)
{
	uint32_t		color;
	unsigned char	bytes[3];

	bytes[0] = ft_atoi(text[0]);
	bytes[1] = ft_atoi(text[1]);
	bytes[2] = ft_atoi(text[2]);
	color = ((uint32_t)bytes[0] << 24 | \
			(uint32_t)bytes[1] << 16 | \
			(uint32_t)bytes[2] << 8 | \
			190);
	return (color);
}

int	find_fc(t_mlx_data *data, char *read_line, t_texture *text)
{
	char	*find_f;
	char	*find_c;
	char	*tmp_line;

	tmp_line = ft_substr(read_line, 0, ft_strlen(read_line) - 1);
	find_f = ft_strchr(tmp_line, 'F');
	find_c = ft_strchr(tmp_line, 'C');
	if ((find_f && !(find_f - tmp_line)) || (find_c && !(find_c - tmp_line)))
	{
		if (find_f)
			text->floor_txt = ft_split(tmp_line + 2, ',');
		if (find_c)
			text->ceiling_txt = ft_split(tmp_line + 2, ',');
	}
	else
	{
		free(tmp_line);
		free(read_line);
		error_msg("check cub file (floor, ceiling)", FC_INIT_ERROR, data);
	}
	free(tmp_line);
	return (0);
}

int	check_fc(t_mlx_data *data, char *map_path, t_texture *text)
{
	int		fd;
	char	*read_line;
	int		flag;

	flag = 1;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		error_msg("file open error", FILE_OPEN_ERROR, data);
	while (1)
	{
		read_line = get_next_line(fd);
		if (!read_line)
			break ;
		if (read_line[0] == '\n')
			flag = 0;
		if (flag)
			find_fc(data, read_line, text);
		free(read_line);
	}
	free(read_line);
	close(fd);
	return (0);
}

int	init_fc(t_mlx_data *data)
{
	t_map		*map_data;
	t_texture	*text;

	map_data = &data->map;
	text = &data->texture;
	text->floor_txt = NULL;
	text->ceiling_txt = NULL;
	check_fc(data, map_data->map_path, text);
	if (!text->floor_txt || !text->ceiling_txt)
		error_msg("check cub file (floor, ceiling)", FC_INIT_ERROR, data);
	text->floor_color = char_to_color(text->floor_txt);
	text->ceiling_color = char_to_color(text->ceiling_txt);
	return (0);
}
