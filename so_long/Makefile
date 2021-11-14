# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/17 19:18:05 by soum              #+#    #+#              #
#    Updated: 2021/11/01 14:59:53 by soum             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = main.c \
	   ./src/check_map.c \
	   ./src/get_next_line.c \
	   ./src/get_next_line_utils.c \
	   ./src/create_window.c \
	   ./src/render_image.c \
	   ./src/render_image2.c \
	   ./src/load_map.c \
	   ./src/key_event.c \
	   ./src/move_player.c \
	   ./src/error.c

LIBFT = libft
LIBFT_LIB = libft/libft.a
MINILIBX = minilibx
INCLUDES = ./includes/so_long.h

CC = gcc
CFLAGES = -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCLUDES)
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	make all -C $(MINILIBX)/
	cp ./minilibx/libmlx.dylib ./
	$(CC) $(CFLAGES) $(OBJS) Libft/libft.a -L./minilibx -lmlx -L./minilibx -lmlx -o $(NAME)

re : fclean all

clean :
	rm -f $(OBJS) $(OBJS_B)
	make clean -C $(LIBFT)
	make clean -C $(MINILIBX)
fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)
	make clean -C $(MINILIBX)
	rm -f libmlx.dylib

