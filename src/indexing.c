/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:50:03 by yossasak          #+#    #+#             */
/*   Updated: 2025/07/07 20:42:18 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*copy_to_array(t_stack *a)
{
	int		*arr;
	t_node	*cur;
	int		i;

	arr = ft_calloc(a->size, sizeof(int));
	if (!arr)
		ps_error_exit();
	cur = a->top;
	i = 0;
	while (i < a->size)
	{
		arr[i++] = cur->val;
		cur = cur->next;
	}
	return (arr);
}

static void	bubble_sort(int *tab, int size)
{
	int	i;
	int	tmp;
	int	sorted;

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

void	index_stack(t_stack *a)
{
	int		*arr;
	t_node	*cur;
	int		i;
	int		j;

	arr = copy_to_array(a);
	bubble_sort(arr, a->size);
	cur = a->top;
	i = 0;
	while (i < a->size)
	{
		j = 0;
		while (arr[j] != cur->val)
			j++;
		cur->val = j;
		cur = cur->next;
		i++;
	}
	free(arr);
}
