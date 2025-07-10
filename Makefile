# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/07 15:49:50 by yossasak          #+#    #+#              #
#    Updated: 2025/07/11 02:21:30 by yossasak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME         = push_swap
NAME_BONUS   = checker_bonus

CC           = cc
CFLAGS       = -Wall -Wextra -Werror -I ./include
BONUS_CFLAGS = $(CFLAGS) -DBONUS_PART

LIBFT_DIR = libft
LIBFT_A   = $(LIBFT_DIR)/libft.a

SRCS_MAND = \
	srcs_mandatory/error.c \
	srcs_mandatory/init.c \
	srcs_mandatory/main.c \
	srcs_mandatory/operations_push.c \
	srcs_mandatory/operations_rev_rotate.c \
	srcs_mandatory/operations_rotate.c \
	srcs_mandatory/operations_swap.c \
	srcs_mandatory/print_utils.c \
	srcs_mandatory/sort_simple.c \
	srcs_mandatory/sort_turk_utils.c \
	srcs_mandatory/sort_turk_utils2.c \
	srcs_mandatory/sort_turk.c \
	srcs_mandatory/stack_utils.c

SRCS_BONUS_ONLY = \
	srcs_bonus/checker_bonus.c \
	srcs_bonus/execute_instructions_bonus.c \
	srcs_bonus/get_next_line_bonus.c \
	srcs_bonus/get_next_line_utils_bonus.c

SRCS_BONUS = $(SRCS_MAND) $(SRCS_BONUS_ONLY)

OBJS_MAND  = $(SRCS_MAND:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS_MAND) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS_MAND) $(LIBFT_A) -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT_A)
	$(CC) $(BONUS_CFLAGS) $(OBJS_BONUS) $(LIBFT_A) -o $@

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS_MAND) $(OBJS_BONUS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
