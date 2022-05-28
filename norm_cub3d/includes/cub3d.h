/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:21:10 by soum              #+#    #+#             */
/*   Updated: 2022/05/28 22:57:39 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../MLX42/include/MLX42/MLX42_Input.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>
# include <math.h>
# include <stdint.h>
# include <fcntl.h>
# include "../Libft/libft.h"
# include "../gnl/get_next_line.h"

# define WIDTH 1024
# define HEIGHT 1024
# define GRID 128
# define IMG_SIZE 32
# define PI 3.1415926535897
# define MAP_SPACE 8
# define SPEED 5
# define MAP_MAX_LEN 1448.0
# define PER_CUBE_LINE WIDTH / 60

typedef struct s_point
{
	double		x;
	double		y;
	double		angle;
	double		wall_len;
	uint32_t	color;
	int			grid_x;
	int			grid_y;
	int			is_line;
	int			type;
}t_point;

typedef struct s_fov
{
	t_point	camera_pos;
	t_point	point[300];
	int		angle;
}t_fov;

typedef struct s_map
{
	int	width;
	int	height;
	char *map;
}t_map;

typedef struct s_mlx_data
{
	mlx_t			*mlx;
	mlx_image_t		*camera_img;
	mlx_image_t		*bg_img;
	mlx_image_t		*cub_img;
	mlx_texture_t	*wall_txt;
	mlx_image_t		*gun_img;
	t_fov			fov;
	t_map			map;
	int				zoom;
}	t_mlx_data;

/** initData.c */
void		init_data(t_mlx_data *data, char *map);



/** Error.c */
void		error_msg(char *msg);

/** Map.c */
int			init_map(t_map *map_data, char *map);
int			check_map(int fd);
void		load_map(t_map *map_data, int fd);


/** void	my_hook(void *param); */
/** void	key_hook(mlx_key_data_t keydata, void *param); */
/** void	put_bg_img(t_mlx_data *data); */
/** void 	set_fov_pos(t_mlx_data *data); */
/** void	detect_wall(t_point *point, t_mlx_data *data, int i); */
/** void	cub_draw(t_mlx_data *data); */
/** void 	cursor_hook(double xpos, double ypos, void* param); */
/** void	put_cub_img(t_mlx_data *data); */
uint32_t	to_le(uint32_t color);
void		fdf_drawline(mlx_image_t *img, t_point *p0, t_point *p1);

#endif
