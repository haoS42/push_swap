/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:50:03 by yossasak          #+#    #+#             */
/*   Updated: 2025/07/07 15:55:41 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_op(const char *s)
{
	ft_putstr_fd((char *)s, 1);
}

void	op_sa_sb(t_stack *s)
{
	t_node	*first;
	t_node	*second;

	if (s->size < 2)
		return ;
	first = pop_top(s);
	second = pop_top(s);
	push_top(s, first);
	push_top(s, second);
	if (s->name == 'a')
		print_op("sa\n");
	else
		print_op("sb\n");
}

void	op_pa(t_stack *a, t_stack *b)
{
	if (!b->size)
		return ;
	push_top(a, pop_top(b));
	print_op("pa\n");
}

void	op_pb(t_stack *a, t_stack *b)
{
	if (!a->size)
		return ;
	push_top(b, pop_top(a));
	print_op("pb\n");
}

void	op_ra_rb(t_stack *s)
{
	if (s->size < 2)
		return ;
	s->top = s->top->next;
	print_op((s->name == 'a') ? "ra\n" : "rb\n");
}

void	op_rra_rrb(t_stack *s)
{
	if (s->size < 2)
		return ;
	s->top = s->top->prev;
	print_op((s->name == 'a') ? "rra\n" : "rrb\n");
}
