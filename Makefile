# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/07 15:49:50 by yossasak          #+#    #+#              #
#    Updated: 2025/07/08 23:58:45 by yossasak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
NAME_BONUS	= checker

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I ./include

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRCS_MAND	= main.c init.c error.c stack_utils.c \
			  operations_push.c operations_swap.c operations_rotate.c \
			  operations_rev_rotate.c sort_simple.c sort_turk.c sort_turk_utils.c
SRCS_MAND_PATH = $(addprefix srcs_mandatory/, $(SRCS_MAND))

SRCS_BONUS	= checker_bonus.c init.c error.c stack_utils.c \
			  operations_push.c operations_swap.c operations_rotate.c \
			  operations_rev_rotate.c get_next_line_bonus.c get_next_line_utils_bonus.c
SRCS_BONUS_PATH = $(addprefix srcs_bonus/, $(SRCS_BONUS))

OBJS_MAND	= $(SRCS_MAND_PATH:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS_PATH:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS_MAND) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJS_MAND) $(LIBFT) -o $(NAME)

bonus:		$(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)

$(LIBFT):
			make -C $(LIBFT_DIR)

clean:
			make -C $(LIBFT_DIR) clean
			rm -f $(OBJS_MAND) $(OBJS_BONUS)

fclean:		clean
			make -C $(LIBFT_DIR) fclean
			rm -f $(NAME) $(NAME_BONUS)

re:			fclean all

.PHONY:		all clean fclean re bonus
