# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 14:41:39 by soum              #+#    #+#              #
#    Updated: 2022/10/03 16:27:52 by soum             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = webserv
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address

SRCS = ./src/main.cpp \
	   ./src/WsInitializer.cpp \
	   ./src/WsException.cpp \
	   ./src/parser/configParser.cpp \
	   ./src/parser/fileReader.cpp \
	   ./src/parser/tokenizer.cpp \
	   ./src/WsConfigInfo.cpp \
	   ./src/WsServer.cpp \
	   ./src/WsASocket.cpp \
	   ./src/WsServerSock.cpp \
	   ./src/WsClientSock.cpp \
	   ./src/WsRequest.cpp \
	   ./src/WsResponse.cpp \
	   ./src/WsIMethod.cpp \
	   ./src/WsPutMethod.cpp \
	   ./src/WsPostMethod.cpp \
	   ./src/WsGetMethod.cpp \

.cpp.o :
	$(CXX) $(CXXFLAGS) -c $< -o $(<:.cpp=.o)

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

debug : all
	$(CXX) $(CXXFLAGS) -g $(SRCS) -o $(NAME)
	$(shell cp ~/vimspector.json ./.vimspector.json)
	$(shell perl -pi -e 's/filename/webserv/g' .vimspector.json)

clean :
	rm -f $(OBJS)
	rm -f .vimspector.json
	rm -rf $(NAME).dSYM

fclean : clean
	rm -f $(NAME)

re : clean all

.PHONY: all clean fclean re debug
