# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/08 16:46:29 by soum              #+#    #+#              #
#    Updated: 2022/04/09 16:10:16 by soum             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
	   Fixed.cpp

.cpp.o :
	$(CXX) $(CXXFLAGS) -c $< -o $(<:.cpp=.o)

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
