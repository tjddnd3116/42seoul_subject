NAME	= libdlinkedlist.a


CC		= cc
CFLAGS	= -Wall -Wextra -Werror
DEBUG	= -g3 -fsanitize=address


SRC		= dlinkedlist_new.c\
		  dlinkedlist_util.c\
		  dlinkedlist_peek.c\
		  dlinkedlist_cur.c\
		  dlinkedlist_dup.c\
		  dlinkedlist_delete.c\
		  dlinkedlist_mergesort.c\
		  dlinkedlist_transfer.c
#		  libft_utils.c
OBJ		= $(SRC:%.c=%.o)


INCLUDE	= dlinkedlist.h
INCL_DIR= ../include


ifeq ($(DEBUG_FLAG), 1)
CFLAGS	+=	$(DEBUG)
endif


all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I. -I$(INCL_DIR)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
