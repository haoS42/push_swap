/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:50:03 by yossasak          #+#    #+#             */
/*   Updated: 2025/07/07 17:24:29 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_pa(t_stack *a, t_stack *b)
{
	if (b->size == 0)
		return ;
	push_top(a, pop_top(b));
	ft_putstr_fd("pa\n", 1);
}

void	op_pb(t_stack *a, t_stack *b)
{
	if (a->size == 0)
		return ;
	push_top(b, pop_top(a));
	ft_putstr_fd("pb\n", 1);
}
