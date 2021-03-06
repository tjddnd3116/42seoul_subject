/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:21:10 by soum              #+#    #+#             */
/*   Updated: 2022/07/18 18:17:19 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../MLX42/include/MLX42/MLX42_Input.h"
# include "../Libft/libft.h"
# include "../gnl/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>
# include <math.h>
# include <stdint.h>
# include <fcntl.h>
# include <time.h>

# define ARG_ERROR 0b10
# define FILE_OPEN_ERROR 0b11
# define FILE_NAME_ERROR 0b11
# define FC_INIT_ERROR 0b100
# define TXT_INIT_ERROR 0b1100
# define MAP_INIT_ERROR 0b11100
# define MLX_INIT_ERROR 0b11100
# define PLAYER_INIT_ERR 0b11100
# define PRESS_ESC 0b111100

# define RED 0xff0000ff

# define GRID 512
# define PLAYER_SIZE 128

# define SCREEN_W 2560
# define SCREEN_H 1440
# define MINIMAP_W 512
# define MINIMAP_H 288

# define PNT_CNT 1280

# define FOV 60
# define ANGLE_SPEED 4
# define SPEED 55

typedef struct s_door
{
	int		is_door_action;
	double	start_x;
	double	end_x;
	double	start_y;
	double	end_y;
	int		grid_x;
	int		grid_y;
	char	act;
}t_door;

typedef struct s_point
{
	double		x;
	double		y;
	double		map_x;
	double		map_y;
	double		angle;
	double		degree;
	double		wall_len;
	uint32_t	color;
	int			grid_x;
	int			grid_y;
	int			is_close_door;
	int			is_open_door;
	char		type;
	int			open_door_grid[2];
	double		open_door_len;
}t_point;

typedef struct s_ray
{
	int		origin_xy[2];
	double	xy[2];
	int		grid[2];
	double	wall_len;
	char	type;
	int		is_close_door;
	int		is_open_door;
	int		open_door_grid[2];
	double	open_door_len;
}t_ray;

typedef struct s_map
{
	int		cub_x;
	int		cub_y;
	int		width;
	int		height;
	char	**map;
	int		cub_size;
	char	*map_path;
	t_door	door_ani;
}t_map;

typedef struct s_screen
{
	int32_t		screen_w;
	int32_t		screen_h;
	int			zoom;
	int			toggle_minimap;
}t_screen;

typedef struct s_image
{
	mlx_image_t	*cub_img;
	mlx_image_t	*minimap_img;
}t_image;

typedef struct s_texture
{
	char			**floor_txt;
	char			**ceiling_txt;
	uint32_t		floor_color;
	uint32_t		ceiling_color;
	mlx_texture_t	*n_wall_txt;
	mlx_texture_t	*s_wall_txt;
	mlx_texture_t	*e_wall_txt;
	mlx_texture_t	*w_wall_txt;
	char			*n_wall_path;
	char			*s_wall_path;
	char			*e_wall_path;
	char			*w_wall_path;
	mlx_texture_t	*door_txt;
}t_texture;

typedef struct s_player
{
	int	mid_pos[2];
	int	pos[2];
	int	scale_size[2];
	int	size;
	int	angle;
	int	grid[2];
	int	scaled_pos[2];
	int	scaled_mid_pos[2];
	int	near_door;
}t_player;

typedef struct s_mlx_data
{
	t_player		player;
	t_map			map;
	mlx_t			*mlx;
	t_screen		screen;
	t_image			image;
	t_texture		texture;
	t_point			pnt[PNT_CNT];
}	t_mlx_data;

/** initData.c */
void		init_data(t_mlx_data *data, char *map);

/** Error.c */
void		error_msg(char *msg, int error_num, t_mlx_data *data);

/** init_fc.c */
int			init_fc(t_mlx_data *data);

/** init_wall.c */
int			init_wall_txt(t_mlx_data *data);

/** InitMap.c */
int			init_map(t_mlx_data *data);
int			check_map(t_mlx_data *data, t_map *map_data, int fd);
int			load_map(t_map *map_data, int fd);

/** InitPlayer.c */
int			init_player(t_mlx_data *data);
void		find_player(t_mlx_data *data, t_player *player, \
		t_map *map_data, char **map);
void		player_pos_scale(t_player *p, t_map *map_data);

/** FreeData.c */
void		free_all_data(t_mlx_data *data, int error_idx);
void		free_map(t_mlx_data *data);

/** Util.c */
uint32_t	to_le(uint32_t color);
int			is_invisible(uint32_t *color);
void		pos_togrid(int *pos, int *grid);
void		get_frametime(void);

/** util2.c */
void		copy_ray_data(t_point *pnt, t_ray *ray);
void		init_ray_data(t_ray *ray, t_mlx_data *data);

/** drawline.c */
void		fdf_drawline(mlx_image_t *img, t_point *p0, t_point *p1);

/** PutPixel.c */
void		put_minimap_pixel(mlx_image_t *mini_img, t_map *map);
void		put_cub_pixel(t_mlx_data *data);
void		put_player_pixel(mlx_image_t *mimi_img, t_player *p, \
		mlx_texture_t *p_txt);
void		put_pixels(t_mlx_data *data);

/** put_pixel2.c */
void		put_razer_pixel(t_mlx_data *data, mlx_image_t *bg_img);
void		put_wall_pixel(t_mlx_data *data, double *start_end_xy, \
		int txt_pos, mlx_texture_t *txt);
void		put_minimap_dark(mlx_image_t *mini_img, t_player *player);

/** Hook.c */
void		scroll_hook(double xdelta, double ydelta, void *param);
void		cursor_hook(double xpos, double ypos, void *param);
void		my_hook(void *param);
void		key_hook(mlx_key_data_t keydata, void *param);

/** door.c */
int			check_door_action(t_ray *pnt, t_map *map_data);
int			is_near_door(t_point *pnt);
void		act_door(t_map *map_data, t_point *pnt);
void		door_ani(t_door *door, t_map *map_data);

/** detect_wall.c */
void		detect_wall(t_mlx_data *data, t_point *pnt);

/** detect_wall2.c */
int			find_y_txt(t_ray *pnt, t_map *map_data, double angle, int *grid_xy);
int			find_x_txt(t_ray *pnt, t_map *map_data, double angle, int *grid_xy);

/** Fov.c */
void		set_fov_pos(t_mlx_data *data);

/** player.move.c */
void		player_move(t_player *p, double x, double y, t_mlx_data *data);

/** get_color.c */
uint32_t	get_player_color(mlx_texture_t *p_txt, t_player *p, int *xy);

/** scaling.c */
void		scale_scn_to_map(int *pos, int *scaled_pos, t_map *map_data);
void		scale_map_to_scn(int *pos, int *scaled_pos, t_map *map_data);
int			scale_map_to_scn_single(int val, int map_size, int scn_size);
void		pnt_scale(t_mlx_data *data, int i);

/** draw_cub.c */
int			draw_txt_pos(t_point *ray, mlx_texture_t *txt, t_door *door);
void		draw_cub(t_mlx_data *data);
void		draw_wall(t_point *pnt, t_mlx_data *data, int i);
#endif
