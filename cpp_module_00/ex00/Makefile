# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 10:30:28 by soum              #+#    #+#              #
#    Updated: 2022/02/14 11:15:18 by soum             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
SRCS = megaphone.cpp

CC = clang++
CFLAGES = -Wall -Wextra -Werror -std=c++98

.cpp.o :
	$(CC) $(CFLAGES) -c $< -o $(<:.cpp=.o)

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGES) $(OBJS) -o $(NAME)

re : fclean all

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

.PHONY: all clean fclean re .cpp.o
