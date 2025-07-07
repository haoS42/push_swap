/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:50:03 by yossasak          #+#    #+#             */
/*   Updated: 2025/07/07 17:26:58 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_chunk(t_stack *a, int base, int width)
{
	t_node	*cur;
	int		i;

	cur = a->top;
	i = 0;
	while (i < a->size)
	{
		if (in_chunk(cur->val, base, width))
			return (1);
		cur = cur->next;
		i++;
	}
	return (0);
}

static void	push_one(t_stack *a, t_stack *b, int base, int width)
{
	if (in_chunk(a->top->val, base, width))
	{
		op_pb(a, b);
		if (b->top->val > base + (width / 2))
			op_ra_rb(b);
	}
	else
		rotate_shortest(a, distance_top_chunk(a, base, width));
}

void	push_chunks(t_stack *a, t_stack *b, int width)
{
	int	base;

	base = 0;
	while (a->size)
	{
		while (has_chunk(a, base, width))
			push_one(a, b, base, width);
		base += width;
	}
}
