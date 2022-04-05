# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 16:28:49 by soum              #+#    #+#              #
#    Updated: 2022/04/05 16:31:33 by soum             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Harl
CXX = C++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
	   Harl.cpp

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
