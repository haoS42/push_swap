/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:50:03 by yossasak          #+#    #+#             */
/*   Updated: 2025/07/07 20:40:36 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

long	ft_atol(const char *nptr);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isdigit(int c);
void	*ft_memset(void *s, int c, size_t len);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(const char *str);

typedef struct s_node
{
	int				val;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
	char	name;
}	t_stack;

void	parse_args(t_stack *a, int argc, char **argv);
void	ps_error_exit(void);

t_node	*new_node(int v);
void	free_stack(t_stack *s);
void	push_top(t_stack *s, t_node *n);
t_node	*pop_top(t_stack *s);
int		distance_top_chunk(t_stack *s, int base, int width);
int		pos_max(t_stack *s);

void	op_sa_sb(t_stack *s);
void	op_pa(t_stack *a, t_stack *b);
void	op_pb(t_stack *a, t_stack *b);
void	op_ra_rb(t_stack *s);
void	op_rra_rrb(t_stack *s);

int		chunk_width(int n);
int		in_chunk(int v, int base, int width);
void	index_stack(t_stack *a);
void	rotate_shortest(t_stack *s, int dist);

void	push_chunks(t_stack *a, t_stack *b, int width);
void	pull_back(t_stack *a, t_stack *b);

#endif
