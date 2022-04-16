# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 20:58:22 by soum              #+#    #+#              #
#    Updated: 2022/04/16 17:08:48 by soum             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = diamondtrap
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow

SRCS = main.cpp \
	   ClapTrap.cpp \
	   ScavTrap.cpp \
	   FragTrap.cpp \
	   DiamondTrap.cpp

.cpp.o :
	$(CXX) $(CXXFLAGS) -c $< -o $(<:.cpp=.o)

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

debug : all
	$(CXX) $(CXXFLAGS) -g $(SRCS) -o $(NAME)
	$(shell cp ~/vimspector.json ./.vimspector.json)
	$(shell perl -pi -e 's/filename/diamondtrap/g' .vimspector.json)

clean :
	rm -f $(OBJS)
	rm -f .vimspector.json
	rm -rf $(NAME).dSYM

fclean : clean
	rm -f $(NAME)

re : clean all

.PHONY : all clean fclean re debug
