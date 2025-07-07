/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:50:03 by yossasak          #+#    #+#             */
/*   Updated: 2025/07/07 17:19:14 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	append_unique(t_stack *a, int v)
{
	t_node	*cur;

	cur = a->top;
	while (cur)
	{
		if (cur->val == v)
			ps_error_exit();
		cur = cur->next;
	}
	push_top(a, new_node(v));
}

void	parse_args(t_stack *a, int argc, char **argv)
{
	int		i;
	long	tmp;

	i = 1;
	while (i < argc)
	{
		if (!argv[i][0])
			ps_error_exit();
		tmp = ft_atol(argv[i]);
		if (tmp < INT_MIN || tmp > INT_MAX)
			ps_error_exit();
		append_unique(a, (int)tmp);
		i++;
	}
}
