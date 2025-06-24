NAME = push_swap
CC = cc
HEADER = push_swap.h
SRC_DIR = src
SRC = push_swap.c ft_atol.c ft_isspace.c ft_dup_check.c ft_exit.c ft_free_nums.c \
	  init_stack.c ft_is_sorted.c ft_swap_commands.c ft_push_commands.c ft_shift.c \
	  ft_reverse.c ft_small_algo.c ft_sort_five.c ft_big_sort.c ft_sort_utils.c \
	  ft_sort_utils_2.c ft_set_target.c
LIBFT = libft.a
FT_PRINTF = libftprintf.a
FT_PRINTF_DIR = ft_printf
LIBFT_DIR = libft
CFLAGS = -Werror -Wextra -Wall
OBJ = $(SRC:.c=.o)

all: $(FT_PRINTF) $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean
	@make -C $(FT_PRINTF_DIR) clean
fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(FT_PRINTF_DIR) fclean
re: fclean all

.PHONY: clean
