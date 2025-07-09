/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:50:03 by yossasak          #+#    #+#             */
/*   Updated: 2025/07/09 23:56:32 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	initial_push(t_stack **a, t_stack **b)
{
	int	size;
	int	pushed;
	int	i;

	size = stack_size(*a);
	pushed = 0;
	i = 0;
	while (i < size && pushed < size / 2)
	{
		if ((*a)->index <= size / 2)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
		i++;
	}
	while (size - pushed > 3)
	{
		pb(a, b);
		pushed++;
	}
}

void	turk_sort(t_stack **a, t_stack **b)
{
	initial_push(a, b);
	sort_three(a);
	while (*b)
	{
		calculate_cost(*a, *b);
		find_cheapest_move(a, b);
	}
}
