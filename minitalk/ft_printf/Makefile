# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/06 09:35:33 by soum              #+#    #+#              #
#    Updated: 2021/09/26 17:31:55 by soum             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGES = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_print_type.c ft_print_type2.c ft_print_minuszero.c ft_utils.c ft_utils2.c ft_put_str.c

INCLUDES = ../includes/ft_printf.h
LIBFT = ../Libft
LIBFT_LIB = libft.a

%.o: %.c
	$(CC) $(CFLAGES) -c $<  -I ../includes

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make all -C $(LIBFT)
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	ar -rcs $@ $^

clean:
	rm -f $(OBJS) $(OBJS_B)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: clean all
