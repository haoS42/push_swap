# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/07 15:49:50 by yossasak          #+#    #+#              #
#    Updated: 2025/07/07 16:41:36 by yossasak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I ./includes
RM = rm -f

SRC =	src/main.c src/parse.c src/error.c src/stack_ops.c src/stack_utils.c src/chunk_utils.c src/morip_sort.c\
		libft/ft_atol_new.c libft/ft_calloc.c libft/ft_isdigit.c libft/ft_memset.c libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strdup.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strjoin.c libft/ft_strlcat.c

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
