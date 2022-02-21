# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 10:30:28 by soum              #+#    #+#              #
#    Updated: 2022/02/21 20:45:42 by soum             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
CC = c++
CFLAGES = -Wall -Wextra -Werror -std=c++98


SRCS = ./megaphone.cpp


OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGES) -o $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re .cpp.o
