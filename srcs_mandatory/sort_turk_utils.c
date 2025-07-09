/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:50:03 by yossasak          #+#    #+#             */
/*   Updated: 2025/07/10 00:01:10 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_target_pos(t_stack *a, int b_index)
{
	t_stack	*current_a;
	int		target_idx;
	int		target_pos;

	target_idx = INT_MAX;
	target_pos = -1;
	current_a = a;
	while (current_a)
	{
		if (current_a->index > b_index && current_a->index < target_idx)
		{
			target_idx = current_a->index;
			target_pos = current_a->index;
		}
		current_a = current_a->next;
	}
	if (target_pos == -1)
	{
		current_a = a;
		while (current_a)
		{
			if (current_a->index < target_idx)
				target_idx = current_a->index;
			current_a = current_a->next;
		}
		target_pos = target_idx;
	}
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

static void	apply_rr(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b, 1);
		(*cost_a)--;
		(*cost_b)--;
	}
}

static void	apply_rrr(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b, 1);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	move_to_a(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	apply_rr(a, b, &cost_a, &cost_b);
	apply_rrr(a, b, &cost_a, &cost_b);
	while (cost_a > 0)
	{
		ra(a, 1);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(a, 1);
		cost_a++;
	}
	while (cost_b > 0)
	{
		rb(b, 1);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(b, 1);
		cost_b++;
	}
	pa(a, b, 1);
}
