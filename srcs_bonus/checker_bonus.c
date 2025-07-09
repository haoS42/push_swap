/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:50:03 by yossasak          #+#    #+#             */
/*   Updated: 2025/07/09 23:52:08 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h" // 自作のGNL
#include <string.h>              // strcmpのため。自作のft_strcmpに置換可

static int	execute_swap_push(char *line, t_stack **a, t_stack **b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(a, 0);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(b, 0);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(a, b, 0);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(a, b, 0);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(a, b, 0);
	else
		return (0);
	return (1);
}

static int	execute_rotate(char *line, t_stack **a, t_stack **b)
{
	if (ft_strcmp(line, "ra\n") == 0)
		ra(a, 0);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(b, 0);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(a, b, 0);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(a, 0);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(b, 0);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(a, b, 0);
	else
		return (0);
	return (1);
}

void	sa(t_stack **a, int print_flag)
{
	swap(a);
	if (print_flag)
		write(1, "sa\n", 3);
}

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
		if (!execute_swap_push(line, &a, &b) && !execute_rotate(line, &a, &b))
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
