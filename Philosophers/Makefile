# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 21:40:55 by soum              #+#    #+#              #
#    Updated: 2021/12/02 21:44:03 by soum             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCS = main.c \

INCLUDES = ./includes/philo.h

CC = gcc
CFLAGES = -Wall -Werror -Wextra

.c.o :
	$(CC) $(CFLAGES) -c $< -o $(<:.c=.o) -I $(INCLUDES)

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGES) $(OBJS) -o $(NAME)

re : fclean all

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)
