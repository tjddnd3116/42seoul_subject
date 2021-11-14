# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/21 16:40:05 by soum              #+#    #+#              #
#    Updated: 2021/09/30 15:37:12 by soum             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER	= server
CLIENT	= client
CC		= gcc
FLAGS	= -Wall -Werror -wextra

LIBFT = libft
PRINTF	= ft_printf
LIBFT_LIB = Libft/libft.a
PRINTF_LIB = ft_printf/libftprintf.a

INCLUDES = ./includes/minitalk.h

%.o: %.c
	$(CC) $(CLFAGES) $< -c -I $(INCLUDES)

all : $(SERVER) $(CLIENT)

$(SERVER) : server.o $(INCLUDES)
	make all -C $(LIBFT)
	make all -C $(PRINTF)
	$(CC) $(CFLAGES) server.o $(LIBFT_LIB) $(PRINTF_LIB) -o $@

$(CLIENT) : client.o $(INCLUDES)
	make all -C $(LIBFT)
	make all -C $(PRINTF)
	$(CC) $(CFLAGES) client.o $(LIBFT_LIB) $(PRINTF_LIB) -o $@

clean :
	make clean -C $(PRINTF)
	make clean -C $(LIBFT)
	rm -f *.o

fclean : clean
	make fclean -C $(LIBFT)
	make fclean -C $(PRINTF)
	rm -f $(SERVER) $(CLIENT)

re : fclean all
