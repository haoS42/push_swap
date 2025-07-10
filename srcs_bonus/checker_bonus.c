/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:50:03 by yossasak          #+#    #+#             */
/*   Updated: 2025/07/10 23:41:21 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "get_next_line_bonus.h"

static bool	process_instructions(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!execute_swap_push(line, a, b) && !execute_rotate(line, a, b))
		{
			free(line);
			return (false);
		}
		free(line);
		line = get_next_line(0);
	}
	return (true);
}

static void	print_result(t_stack *a, t_stack *b)
{
	if (is_sorted(a) && stack_size(b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

static void	exit_error_and_free(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	exit_error();
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	init_stack_a(&a, argv);
	if (!process_instructions(&a, &b))
		exit_error_and_free(&a, &b);
	print_result(a, b);
	free_stack(&a);
	return (0);
}
