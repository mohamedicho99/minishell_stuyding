NAME = minishell
SRC = main.c \
	  src/utils/token_utils.c  \
	  src/utils/return_token_type.c \
	  src/libft/ft_memcpy.c \
	  src/libft/is_delimiter.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS = -lreadline

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(LIBS)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
