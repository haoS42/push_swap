/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:50:03 by yossasak          #+#    #+#             */
/*   Updated: 2025/07/11 00:12:21 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	final_rotation(t_stack **a)
{
	int		lowest_pos;
	int		size;
	t_stack	*current;

	lowest_pos = 0;
	size = stack_size(*a);
	current = *a;
	while (current)
	{
		if (current->index == 0)
			break ;
		lowest_pos++;
		current = current->next;
	}
	if (lowest_pos > size / 2)
	{
		while ((*a)->index != 0)
			rra(a);
	}
	else
	{
		while ((*a)->index != 0)
			ra(a);
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size <= 1 || is_sorted(*a))
		return ;
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else
		turk_sort(a, b);
	if (!is_sorted(*a))
		final_rotation(a);
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
	assign_index(a);
	sort_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
