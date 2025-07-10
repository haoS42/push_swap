# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/07 15:49:50 by yossasak          #+#    #+#              #
#    Updated: 2025/07/11 00:10:47 by yossasak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
NAME_BONUS	= checker
CC			= cc

CFLAGS		= -Wall -Wextra -Werror -I ./include

BONUS_CFLAGS= $(CFLAGS) -DBONUS_PART

SRCS_MAND	= srcs_mandatory/main.c srcs_mandatory/init.c ... srcs_mandatory/operations_swap.c
SRCS_BONUS	= srcs_bonus/checker_bonus.c srcs_bonus/init.c ... srcs_bonus/operations_swap.c

OBJS_MAND	= $(SRCS_MAND:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS_MAND)
			$(CC) $(CFLAGS) $(OBJS_MAND) -o $(NAME)

bonus:		$(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
			$(CC) $(BONUS_CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

srcs/main.o: srcs/main.c
	$(CC) $(CFLAGS) -c $< -o $@

srcs/checker_bonus.o: srcs/checker_bonus.c
	$(CC) $(BONUS_CFLAGS) -c $< -o $@
