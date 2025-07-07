/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morip_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:50:03 by yossasak          #+#    #+#             */
/*   Updated: 2025/07/07 15:57:52 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	indexing(t_stack *a)
{
	int		*arr;
	t_node	*cur;
	int		i;

	arr = (int *)malloc(sizeof(int) * a->size);
	if (!arr)
		ps_error_exit();
	cur = a->top;
	i = 0;
	while (i < a->size)
	{
		arr[i++] = cur->val;
		cur = cur->next;
	}
	ft_sort_int_tab(arr, a->size);
	cur = a->top;
	while (cur)
	{
		i = 0;
		while (arr[i] != cur->val)
			i++;
		cur->val = i;
		cur = cur->next;
	}
	free(arr);
}

static void	rot_to_top(t_stack *s, int dist)
{
	if (dist <= s->size / 2)
		while (dist--)
			op_ra_rb(s);
	else
	{
		dist = s->size - dist;
		while (dist--)
			op_rra_rrb(s);
	}
}

static void	push_chunks(t_stack *a, t_stack *b, int width)
{
	int	base;
	int	pushed;
	int	dist;

	base = 0;
	while (a->size)
	{
		pushed = 0;
		while (pushed < width && a->size)
		{
			if (in_chunk(a->top->val, base, width))
			{
				op_pb(a, b);
				if (b->top->val > base + width / 2)
					op_ra_rb(b);
				pushed++;
			}
			else
			{
				dist = distance_to_top(a, base);
				if (dist > a->size)
					dist = distance_to_top(a, base + width - 1);
				rot_to_top(a, dist);
			}
		}
		base += width;
	}
}

static void	pull_back(t_stack *a, t_stack *b)
{
	int	dist;

	while (b->size)
	{
		dist = pos_max(b);
		rot_to_top(b, dist);
		op_pa(a, b);
	}
}

void	morip_sort(t_stack *a, t_stack *b)
{
	int	w;

	indexing(a);
	w = chunk_size(a->size);
	push_chunks(a, b, w);
	pull_back(a, b);
}
