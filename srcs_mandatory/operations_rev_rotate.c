/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:50:03 by yossasak          #+#    #+#             */
/*   Updated: 2025/07/09 23:56:18 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*stack = last;
}

void	rra(t_stack **a, int print_flag)
{
	reverse_rotate(a);
	if (print_flag)
		write(1, "rra\n", 3);
}

void	rrb(t_stack **b, int print_flag)
{
	reverse_rotate(b);
	if (print_flag)
		write(1, "rrb\n", 3);
}

void	rrr(t_stack **a, t_stack **b, int print_flag)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print_flag)
		write(1, "rrr\n", 3);
}
