# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 14:41:39 by soum              #+#    #+#              #
#    Updated: 2022/05/16 19:40:54 by soum             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c

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
	$(CC) $(CFLAGS) -g $(SRCS) -o $(NAME)
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
