# Simple Makefile for minishell project

NAME = minishell
SRC = main.c token_utils.c return_token_type.c
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
