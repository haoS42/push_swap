/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:50:03 by yossasak          #+#    #+#             */
/*   Updated: 2025/07/11 01:40:44 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;



void	sort_stack(t_stack **a, t_stack **b);

void	init_stack_a(t_stack **a, char **argv);
void	assign_index(t_stack *a);

void	exit_error(void);
long	ft_atol(const char *str);
int		is_duplicate(t_stack *a, int n);
int		is_numeric(char *str);

t_stack	*find_last(t_stack *stack);
t_stack	*find_highest_node(t_stack *stack);
int		stack_size(t_stack *stack);
int		is_sorted(t_stack *stack);
void	free_stack(t_stack **stack);

void	sort_three(t_stack **a);

void	turk_sort(t_stack **a, t_stack **b);

void	calculate_cost(t_stack *a, t_stack *b);
void	find_cheapest_move(t_stack **a, t_stack **b);
void	move_to_a(t_stack **a, t_stack **b, int cost_a, int cost_b);
int		get_target_pos(t_stack *a, int b_index);

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

void	print_op(const char *op);

#endif
