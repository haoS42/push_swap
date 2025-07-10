/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:50:03 by yossasak          #+#    #+#             */
/*   Updated: 2025/07/10 23:44:31 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	add_node(t_stack **stack, int n)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		exit_error();
	new_node->value = n;
	new_node->index = -1;
	new_node->next = NULL;
	if (!*stack)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last = find_last(*stack);
		last->next = new_node;
		new_node->prev = last;
	}
}

void	init_stack_a(t_stack **a, char **argv)
{
	int		i;
	long	n;

	i = 1;
	while (argv[i])
	{
		if (!is_numeric(argv[i]))
			exit_error();
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			exit_error();
		if (is_duplicate(*a, (int)n))
			exit_error();
		add_node(a, (int)n);
		i++;
	}
}

void	assign_index(t_stack *a)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;
	int		size;

	size = stack_size(a);
	while (size > 0)
	{
		ptr = a;
		highest = NULL;
		value = INT_MIN;
		while (ptr)
		{
			if (ptr->value > value && ptr->index == -1)
			{
				value = ptr->value;
				highest = ptr;
			}
			ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = size - 1;
		size--;
	}
}
