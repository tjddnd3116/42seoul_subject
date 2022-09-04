/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:07:14 by soum              #+#    #+#             */
/*   Updated: 2022/09/04 15:07:14 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_config.h"

static const char	*g_texture_id_list[TEXTURE_LIST_NUM] = {
	"EA",
	"WE",
	"SO",
	"NO",
	"DO",
	"F",
	"C"
};

static int		check_read_line(char **splited_words);
static int		load_info(int texture_idx, t_texture_list *texture_list,
					const char *option);
static uint32_t	char_to_color(char **text);

int	check_config_path(const char *path)
{
	int		fd;
	char	*filename_ptr;

	filename_ptr = ft_strrchr(path, '.');
	if (filename_ptr == NULL
		|| ft_strncmp(filename_ptr, ".cub", 5))
		error_handler(FILENAME_ERROR);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_handler(FILE_OPEN_ERROR);
	collect_fd_garbage(fd);
	return (fd);
}

void	get_config_info(int fd, t_mlx_data *mlx_data)
{
	char			*read_line;
	char			**splited_words;
	int				option_bit_flag;

	option_bit_flag = 0;
	while (1)
	{
		read_line = get_next_line(fd);
		if (!read_line || is_map(read_line))
			break ;
		splited_words = ft_split(read_line, " \t\n");
		free(read_line);
		if (splited_words[0] != NULL)
		{
			collect_ptr_2d_garbage((void **)splited_words);
			option_bit_flag = load_info(check_read_line(splited_words),
					&mlx_data->texture_list, splited_words[1]);
		}
		free_splited_arr(splited_words);
		collect_ptr_2d_garbage(NULL);
	}
	if (option_bit_flag != ALL_OPTION_FILLED)
		error_handler(CONFIG_NOT_ENOUGH_OPTION_ERROR);
	free(read_line);
	gnl_flush(fd);
}

int	check_read_line(char **splited_words)
{
	int		words_size;
	int		txt_idx;

	words_size = count_splited_words(splited_words);
	if (words_size != 2)
		error_handler(CONFIG_FORMAT_ERROR);
	txt_idx = 0;
	while (txt_idx < TEXTURE_LIST_NUM)
	{
		if (ft_strncmp(splited_words[0], g_texture_id_list[txt_idx],
				ft_strlen(g_texture_id_list[txt_idx]) + 1) == 0)
			break ;
		txt_idx++;
	}
	if (txt_idx == TEXTURE_LIST_NUM)
		error_handler(CONFIG_FORMAT_ERROR);
	return (txt_idx);
}

int	load_info(int texture_idx, t_texture_list *texture_list,
	const char *option)
{
	static int	duplicate_detector = 0;
	char		**split_rgb;

	if (duplicate_detector & (1 << texture_idx))
		error_handler(CONFIG_DUPLICATE_ERROR);
	duplicate_detector |= 1 << texture_idx;
	if (texture_idx >= 5)
	{
		split_rgb = ft_split(option, ",");
		*((uint32_t *)texture_list + texture_idx - 5)
			= char_to_color(split_rgb);
	}
	else
	{
		*((mlx_texture_t **)&texture_list->wall + texture_idx) =
			mlx_load_png(option);
		if (!(*((mlx_texture_t **)&texture_list->wall + texture_idx)))
			error_handler(TEXTURE_LOAD_ERROR);
	}
	return (duplicate_detector);
}

uint32_t	char_to_color(char **text)
{
	uint32_t		color;
	int				bytes;
	int				idx;

	idx = 0;
	color = 0;
	if (count_splited_words(text) != 3)
	{
		free_splited_arr(text);
		error_handler(CONFIG_INVALID_RGB_ERROR);
	}
	while (idx < 3)
	{
		bytes = ft_atoi(text[idx]);
		if (bytes < 0 || bytes > 255)
		{
			free_splited_arr(text);
			error_handler(CONFIG_INVALID_RGB_ERROR);
		}
		color |= (uint32_t)bytes << (3 - idx) * 8;
		++idx;
	}
	color |= 190;
	free_splited_arr(text);
	return (color);
}
