# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 11:22:34 by soum              #+#    #+#              #
#    Updated: 2022/03/11 12:38:26 by soum             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
CC = c++
CFLAGES = -Wall -Wextra -Werror -std=c++98

SRCS = PhoneBook.cpp \
			 info.cpp \
			 main.cpp

INC = ./PhoneBook.hpp \
			./info.hpp

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
