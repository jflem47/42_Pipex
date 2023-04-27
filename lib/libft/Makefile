SRCS	=	ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_split.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_split.c \
			ft_strtrim.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_putnbr_base.c \

OBJS		= $(addprefix $(BIN_DIR)/, $(SRCS:.c=.o))

NAME		= libft.a
LIBC		= ar rcs
LIBR		= ranlib
CC			= gcc
RM			= rm -f
RM_DIR		= rm -rf
CFLAGS		= -Wall -Wextra -Werror
BIN_DIR 	= bin

all: $(NAME)

$(BIN_DIR)/%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(BIN_DIR) $(OBJS)
	@$(LIBC) $(NAME) $(OBJS)
	@$(LIBR) $(NAME)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

clean:
	@$(RM_DIR) $(BIN_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all