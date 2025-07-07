/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:50:03 by yossasak          #+#    #+#             */
/*   Updated: 2025/07/07 17:24:03 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa_sb(t_stack *s)
{
	t_node	*f;
	t_node	*snd;

	if (s->size < 2)
		return ;
	f = pop_top(s);
	snd = pop_top(s);
	push_top(s, f);
	push_top(s, snd);
	if (s->name == 'a')
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
}
