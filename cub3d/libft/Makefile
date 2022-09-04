CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_isalpha.c ft_isdigit.c\
	ft_isalnum.c ft_isascii.c\
	ft_isprint.c ft_strlen.c\
	ft_isspace.c ft_ishex.c\
	ft_abs.c ft_swap.c\
	ft_max.c\
	ft_memset.c ft_bzero.c\
	ft_memcpy.c ft_memmove.c\
	ft_strlcpy.c ft_strlcat.c\
	ft_toupper.c ft_tolower.c\
	ft_strchr.c ft_strrchr.c\
	ft_strcmp.c\
	ft_strncmp.c ft_memchr.c\
	ft_memcmp.c ft_strnstr.c\
	ft_atoi.c ft_atoi_ptr.c\
	ft_htoi.c ft_calloc.c\
	ft_strdup.c ft_substr.c\
	ft_strndup.c\
	ft_strjoin.c ft_strtrim.c\
	ft_split.c ft_itoa.c\
	ft_strmapi.c ft_striteri.c\
	ft_putchar_fd.c ft_putstr_fd.c\
	ft_putendl_fd.c ft_putnbr_fd.c

BNS = ft_lstnew.c ft_lstadd_front.c\
	ft_lstsize.c ft_lstlast.c\
	ft_lstadd_back.c ft_lstdelone.c\
	ft_lstclear.c ft_lstiter.c\
	ft_lstmap.c

ADD = ft_execvpe.c ft_print_memory.c
SRC += $(ADD)

OBJS = $(SRC:%.c=%.o)
BNS_OBJS = $(BNS:%.c=%.o)

BNS_FLAG =

ifeq ($(BNS_FLAG), 1)
OBJS += $(BNS_OBJS)
endif

ifeq ($(DEBUG_FLAG), 1)
CFLAGS	+=	-g3 -fsanitize=address
endif

HDR = libft.h

all: $(NAME)

bonus:
	make BNS_FLAG=1

$(NAME): $(OBJS)
	ar rcs $@ $^

$(OBJS): %.o : %.c
	$(CC) $(CFLAGS) $< -c -o $@ -I.

clean:
	@rm -f $(OBJS) $(BNS_OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
