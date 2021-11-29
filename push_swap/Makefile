# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 18:04:53 by soum              #+#    #+#              #
#    Updated: 2021/11/29 16:06:03 by soum             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = main.c \
	   src/util.c \
	   src/error.c \
	   src/sort.c \
	   src/swap.c \
	   src/push.c \
	   src/rotate.c \
	   src/reverse.c \
	   src/pop_push.c \
	   src/under_5_size_sort.c \
	   src/find_min_max_locate.c \
	   src/find_pivot.c \
	   src/a_to_b.c \
	   src/b_to_a.c \

LIBFT = Libft
LIBFT_LIB = Libft/libft.a
INCLUDES = ./includes/push_swap.h

CC = gcc
CFLAGES = -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGES) -c $< -o $(<:.c=.o) -I $(INCLUDES)

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	$(CC) $(CFLAGES) $(OBJS) $(LIBFT_LIB) -o $(NAME)

re : fclean all

clean :
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean : clean
	rm -f $(NAME)
	rm -f $(LIBFT_LIB)
