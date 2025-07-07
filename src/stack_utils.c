/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:50:03 by yossasak          #+#    #+#             */
/*   Updated: 2025/07/07 17:29:53 by yossasak         ###   ########.fr       */
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
