/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:50:03 by yossasak          #+#    #+#             */
/*   Updated: 2025/07/07 20:52:04 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos_min(t_stack *s)
{
	t_node	*cur;
	int		min;
	int		i;
	int		pos;

	cur = s->top;
	min = cur->val;
	pos = 0;
	i = 0;
	while (++i < s->size)
	{
		cur = cur->next;
		if (cur->val < min)
		{
			min = cur->val;
			pos = i;
		}
	}
	return (pos);
}

int	pos_max(t_stack *s)
{
	t_node	*cur;
	int		max;
	int		i;
	int		pos;

	cur = s->top;
	max = cur->val;
	pos = 0;
	i = 0;
	while (++i < s->size)
	{
		cur = cur->next;
		if (cur->val > max)
		{
			max = cur->val;
			pos = i;
		}
	}
	return (pos);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;
	int	sorted;

	if (!tab || size < 2)
		return ;
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				sorted = 0;
			}
			i++;
		}
	}
}

int	chunk_width(int n)
{
	int	w;

	w = 1;
	while (w * w < n)
		w++;
	return (w);
}

int	in_chunk(int v, int base, int width)
{
	return (v >= base && v < base + width);
}
