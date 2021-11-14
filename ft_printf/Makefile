# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/06 09:35:33 by soum              #+#    #+#              #
#    Updated: 2021/09/11 16:02:50 by soum             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = Libft
LIBFT_LIB = libft.a

CC = gcc
CFLAGES = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_print_type.c ft_print_type2.c ft_put_str.c ft_print_minuszero.c ft_utils.c ft_utils2.c
SRCS_B = ft_printf.c ft_print_type.c ft_print_type2.c ft_put_str.c ft_print_minuszero.c ft_utils.c ft_utils2.c

.c.o :
	$(CC) $(CFLAGES) -c $< -o $(<:.c=.o) -I.

OBJS_B = $(SRCS_B:.c=.o)
OBJS = $(SRCS:.c=.o)

ifdef WITH_BONUS
	OBJ_FILES = $(OBJS_B)
else
	OBJ_FILES = $(OBJS)
endif


all: $(NAME)

$(NAME): $(OBJ_FILES)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	ar -rcs $@ $^

bonus :
	make WITH_BONUS=1 all
clean:
	rm -f $(OBJS) $(OBJS_B)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: clean all
