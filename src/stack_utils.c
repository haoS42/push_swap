/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:50:03 by yossasak          #+#    #+#             */
/*   Updated: 2025/07/07 16:13:24 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int v)
{
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
	if (!n)
		ps_error_exit();
	n->val = v;
	n->next = NULL;
	n->prev = NULL;
	return (n);
}

void	free_stack(t_stack *s)
{
	t_node	*cur;
	t_node	*tmp;

	cur = s->top;
	while (cur && s->size--)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
}

void	push_top(t_stack *s, t_node *n)
{
	if (!n)
		return ;
	if (!s->top)
	{
		n->next = n;
		n->prev = n;
	}
	else
	{
		n->next = s->top;
		n->prev = s->top->prev;
		s->top->prev->next = n;
		s->top->prev = n;
	}
	s->top = n;
	s->size++;
}

t_node	*pop_top(t_stack *s)
{
	t_node	*n;

	if (!s->top)
		return (NULL);
	n = s->top;
	if (s->size == 1)
		s->top = NULL;
	else
	{
		s->top->prev->next = s->top->next;
		s->top->next->prev = s->top->prev;
		s->top = s->top->next;
	}
	n->next = NULL;
	n->prev = NULL;
	s->size--;
	return (n);
}

int	distance_to_top(t_stack *s, int target)
{
	t_node	*cur;
	int		i;

	cur = s->top;
	i = 0;
	while (i < s->size && cur->val != target)
	{
		cur = cur->next;
		i++;
	}
	return (i);
}

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
