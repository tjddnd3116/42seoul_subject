# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/08 16:46:29 by soum              #+#    #+#              #
#    Updated: 2022/04/08 21:15:23 by soum             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsp
CXX = C++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
	   Fixed.cpp \
	   Point.cpp \
	   Bsp.cpp

.cpp.o :
	$(CC) $(CXXFLAGS) -c $< -o $(<:.cpp=.o)

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : clean all

.PHONY : all clean fclean re
