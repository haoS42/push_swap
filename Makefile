# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/07 15:49:50 by yossasak          #+#    #+#              #
#    Updated: 2025/07/07 20:53:29 by yossasak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I ./includes
RM = rm -f

SRC =	\
src/main.c src/parse.c src/error.c \
src/stack_utils.c src/stack_utils2.c \
src/rot_utils.c src/indexing.c \
src/chunk_push.c src/chunk_pull.c \
src/op_swap.c src/op_push.c src/op_rotate.c \
libft/ft_calloc.c libft/ft_atol.c \
libft/ft_strlen.c libft/ft_putstr_fd.c libft/ft_memset.c \
libft/ft_bzero.c libft/ft_isdigit.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(INCLUDES) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
