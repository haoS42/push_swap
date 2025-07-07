/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:50:03 by yossasak          #+#    #+#             */
/*   Updated: 2025/07/07 17:20:00 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	distance_top_chunk(t_stack *s, int base, int width)
{
	t_node	*cur;
	int		i;

	cur = s->top;
	i = 0;
	while (i < s->size && !in_chunk(cur->val, base, width))
	{
		cur = cur->next;
		i++;
	}
	return (i);
}

void	rotate_shortest(t_stack *s, int dist)
{
	if (dist <= s->size / 2)
	{
		while (dist--)
			op_ra_rb(s);
	}
	else
	{
		dist = s->size - dist;
		while (dist--)
			op_rra_rrb(s);
	}
}
