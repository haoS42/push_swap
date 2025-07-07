/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:50:03 by yossasak          #+#    #+#             */
/*   Updated: 2025/07/07 17:24:45 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ra_rb(t_stack *s)
{
	if (s->size < 2)
		return ;
	s->top = s->top->next;
	if (s->name == 'a')
		ft_putstr_fd("ra\n", 1);
	else
		ft_putstr_fd("rb\n", 1);
}

void	op_rra_rrb(t_stack *s)
{
	if (s->size < 2)
		return ;
	s->top = s->top->prev;
	if (s->name == 'a')
		ft_putstr_fd("rra\n", 1);
	else
		ft_putstr_fd("rrb\n", 1);
}
