/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:50:03 by yossasak          #+#    #+#             */
/*   Updated: 2025/07/09 23:24:45 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	*stack = second;
}

void	sa(t_stack **a, int print_flag)
{
	swap(a);
	if (print_flag)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int print_flag)
{
	swap(b);
	if (print_flag)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int print_flag)
{
	swap(a);
	swap(b);
	if (print_flag)
		write(1, "ss\n", 3);
}
