/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:50:03 by yossasak          #+#    #+#             */
/*   Updated: 2025/07/11 04:05:22 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	find_next_greater_pos(t_stack *a, int b_index)
{
	int		pos;
	int		target_pos;
	int		target_idx;
	t_stack	*cur;

	pos = 0;
	target_pos = -1;
	target_idx = INT_MAX;
	cur = a;
	while (cur)
	{
		if (cur->index > b_index && cur->index < target_idx)
		{
			target_idx = cur->index;
			target_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (target_pos);
}

static int	find_smallest_pos(t_stack *a)
{
	int		pos;
	int		target_pos;
	int		min_idx;
	t_stack	*cur;

	pos = 0;
	target_pos = -1;
	min_idx = INT_MAX;
	cur = a;
	while (cur)
	{
		if (cur->index < min_idx)
		{
			min_idx = cur->index;
			target_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (target_pos);
}

int	get_target_pos(t_stack *a, int b_index)
{
	int	target_pos;

	target_pos = find_next_greater_pos(a, b_index);
	if (target_pos == -1)
		target_pos = find_smallest_pos(a);
	return (target_pos);
}

void	calculate_cost(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	int		size_a;
	int		size_b;
	int		pos;
	int		target_pos_val;

	current_b = b;
	size_a = stack_size(a);
	size_b = stack_size(b);
	pos = 0;
	while (current_b)
	{
		target_pos_val = get_target_pos(a, current_b->index);
		if (pos > size_b / 2)
			current_b->cost_b = (size_b - pos) * -1;
		else
			current_b->cost_b = pos;
		if (target_pos_val > size_a / 2)
			current_b->cost_a = (size_a - target_pos_val) * -1;
		else
			current_b->cost_a = target_pos_val;
		current_b = current_b->next;
		pos++;
	}
}

void	find_cheapest_move(t_stack **a, t_stack **b)
{
	t_stack	*current;
	int		cheapest;
	int		cost_a;
	int		cost_b;
	int		current_cost;

	current = *b;
	cheapest = INT_MAX;
	while (current)
	{
		current_cost = abs(current->cost_a) + abs(current->cost_b);
		if (current_cost < cheapest)
		{
			cheapest = current_cost;
			cost_a = current->cost_a;
			cost_b = current->cost_b;
		}
		current = current->next;
	}
	move_to_a(a, b, cost_a, cost_b);
}
