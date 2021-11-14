/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:29:32 by soum              #+#    #+#             */
/*   Updated: 2021/11/01 16:24:33 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>

# define MAP "01PCE"

typedef struct s_obj
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_obj;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_image;
typedef struct s_window
{
	char		**map;
	int			move_count;
	void		*mlx;
	void		*win;
	int			map_x;
	int			map_y;
	int			exit_count;
	int			item_count;
	int			cube_size;
	t_pos		player;
	t_pos		screen_size;
	t_image		img;
	t_obj		obj_wall;
	t_obj		obj_player;
	t_obj		obj_item;
	t_obj		obj_exit;
}	t_window;

typedef struct s_map
{
	int	is_P;
	int	is_C;
	int	is_E;
	int	len;
	int	all_wall;
}	t_map;
//check_map.c
int		check_ber(t_window *window, char *ber);
//create_window.c
void	create_window(t_window *window);
//render_image.c
void	render_image(t_window *window);
//load_map.c
void	load_map(char *ber, t_window *window);
//render_image2.c
int		is_background_color(t_obj *obj, char *color);
int		rendering(t_window *window);
//key_event.c
void	key_event(t_window *window);
//move_player.c
void	move_player(t_window *window, int keycode);
//error.c
void	error_msg_exit(char *msg);
int		fin_game(t_window *window);
void	free_all_map(t_window *window, int len);
int		stop_game(t_window *window);
#endif
