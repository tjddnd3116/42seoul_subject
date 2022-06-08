# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 14:41:39 by soum              #+#    #+#              #
#    Updated: 2022/06/08 16:05:04 by soum             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror -o3
#-fsanitize=address -g

SRCS = main.c \
	   ./gnl/get_next_line.c \
	   ./gnl/get_next_line_utils.c \
	   ./srcs/Error.c \
	   ./srcs/FreeData.c \
	   ./srcs/InitData.c \
	   ./srcs/init_fc.c \
	   ./srcs/init_wall.c \
	   ./srcs/InitMap.c \
	   ./srcs/InitMlx.c \
	   ./srcs/InitPlayer.c \
	   ./srcs/Util.c \
	   ./srcs/drawline.c \
	   ./srcs/PutPixel.c \
	   ./srcs/put_pixel2.c \
	   ./srcs/Hook.c \
	   ./srcs/Fov.c \
	   ./srcs/detect_wall.c \
	   ./srcs/detect_wall2.c \
	   ./srcs/player_move.c \
	   ./srcs/get_color.c \
	   ./srcs/scaling.c \
	   ./srcs/draw_cub.c \
	   ./srcs/door.c \


LIBFT = libft
LIBFT_LIB = libft/libft.a
MLX42 = MLX42
MLX42_LIB = MLX42/libmlx42.a
INCLUDES = ./includes/cub3d.h


.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCLUDES)

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)
	make all -C $(MLX42)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX42_LIB) -I include -lglfw -L "/Users/soum/.brew/opt/glfw/lib/" -o $(NAME)

debug : all
	$(CC) $(CFLAGS) -g $(OBJS) $(LIBFT_LIB) $(MLX42_LIB) -I include -lglfw -L "/Users/soum/.brew/opt/glfw/lib/" -o $(NAME)
	$(shell cp ~/vimspector.json ./.vimspector.json)
	$(shell perl -pi -e 's/filename/cub3d/g' .vimspector.json)

clean :
	rm -f $(OBJS)
	rm -f .vimspector.json
	rm -rf $(NAME).dSYM
	make clean -C $(LIBFT)
	make clean -C $(MLX42)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)
	make fclean -C $(MLX42)

re : clean all

.PHONY: all clean fclean re debug
