/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_pull..c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:50:03 by yossasak          #+#    #+#             */
/*   Updated: 2025/07/07 17:22:23 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bring_max_top(t_stack *b)
{
	int	dist;

	dist = pos_max(b);
	rotate_shortest(b, dist);
}

void	pull_back(t_stack *a, t_stack *b)
{
	while (b->size)
	{
		bring_max_top(b);
		op_pa(a, b);
	}
}
