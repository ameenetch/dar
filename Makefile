NAME = push_swap

NAME_BONUS = checker

CFLAGS = -Wall -Wextra -Werror

CC = cc

MAIN_SRC = push_swap.c linked_list_zone/lst_manipulation_2.c linked_list_zone/lst_manipulations_1.c \
			moves/push_to_px_moves.c moves/shift_down_rrx_moves.c moves/shift_up_rx_moves.c moves/swap_sx_moves.c \
			sort_process/sort_five.c sort_process/sort_foor.c sort_process/sort_more_five.c sort_process/sort_three.c sort_process/sort_two.c \
			split_and_atoi/ft_atoi.c split_and_atoi/ft_split.c utils_checking_parsing/chekker_function.c utils_checking_parsing/chekker.c utils_checking_parsing/utils.c 

BONUS_SRC = bonus/get_next_bonus/get_next_line_bonus.c bonus/get_next_bonus/get_next_line_utils_bonus.c \
			bonus/moves_bonus/push_to_px_moves_bonus.c bonus/moves_bonus/shift_down_rrx_moves_bonus.c bonus/moves_bonus/shift_up_rx_moves_bonus.c bonus/moves_bonus/swap_sx_moves_bonus.c \
			bonus/split_and_atoi_bonus/ft_atoi_bonus.c bonus/split_and_atoi_bonus/ft_split_bonus.c \
			bonus/utils_bonus/utils_linked_list_bonus.c bonus/utils_bonus/utils_one_bonus.c bonus/utils_bonus/utils_tree_bonus.c bonus/utils_bonus/utils_two_bonus.c \
			bonus/cheker_bonus.c 

MAIN_OBJ = $(MAIN_SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(MAIN_OBJ) -o $(NAME)

$(MAIN_OBJ): %.o: %.c push_swap.h
	$(CC) -c $(CFLAGS) $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS) : $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(NAME_BONUS)

$(BONUS_OBJ):%.o: %.c bonus/cheker_bonus.h
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	@rm -f $(MAIN_OBJ)
	@rm -f $(BONUS_OBJ)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)

re: fclean all