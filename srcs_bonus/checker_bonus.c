/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:50:03 by yossasak          #+#    #+#             */
/*   Updated: 2025/07/09 00:59:27 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h" // 自作のGNL
#include <string.h> // strcmpのため。自作のft_strcmpに置換可

static int	execute_instruction(char *line, t_stack **a, t_stack **b)
{
	if (strcmp(line, "sa\n") == 0)
		sa(a);
	else if (strcmp(line, "sb\n") == 0)
		sb(b);
	else if (strcmp(line, "ss\n") == 0)
		ss(a, b);
	else if (strcmp(line, "pa\n") == 0)
		pa(a, b);
	else if (strcmp(line, "pb\n") == 0)
		pb(a, b);
	else if (strcmp(line, "ra\n") == 0)
		ra(a);
	else if (strcmp(line, "rb\n") == 0)
		rb(b);
	else if (strcmp(line, "rr\n") == 0)
		rr(a, b);
	else if (strcmp(line, "rra\n") == 0)
		rra(a);
	else if (strcmp(line, "rrb\n") == 0)
		rrb(b);
	else if (strcmp(line, "rrr\n") == 0)
		rrr(a, b);
	else
		return (0);
	return (1);
}

void sa(t_stack **a) { /* swap logic */ }


int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	init_stack_a(&a, argv);
	line = get_next_line(0);
	while (line)
	{
		if (!execute_instruction(line, &a, &b))
		{
			free(line);
			exit_error();
		}
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(a) && stack_size(b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	return (0);
}
