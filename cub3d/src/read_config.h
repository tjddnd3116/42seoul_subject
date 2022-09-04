/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_config.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:07:16 by soum              #+#    #+#             */
/*   Updated: 2022/09/04 15:07:16 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_CONFIG_H
# define READ_CONFIG_H

# include <fcntl.h>
# include <unistd.h>

# include "cub3d.h"
# include "error.h"
# include "get_next_line.h"
# include "garbage_collector/garbage_collector.h"

# define TEXTURE_LIST_NUM (7)
# define ALL_OPTION_FILLED (0b1111111)

void	get_config_info(int fd, t_mlx_data *mlx_data);
int		check_config_path(const char *path);
int		is_map(const char *read_line);
int		is_map_line(const char *read_line);
void	free_splited_arr(char **splited_words);
int		count_splited_words(char **splited_words);
char	*remove_newline(char *read_line);
void	gnl_flush(int fd);

#endif
