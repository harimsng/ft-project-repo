/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:57:01 by hseong            #+#    #+#             */
/*   Updated: 2022/04/04 11:37:17 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_deque.h"

# define INT_MIN (-2147483648LL)
# define INT_MAX (2147483647)
# define A_DEQUE (1)
# define B_DEQUE (0)
# define TRUE (1)
# define FALSE (0)
# define HEAD (1)
# define TAIL (0)
# define INC (1)
# define DEC (0)

typedef int		t_bool;
typedef void	(*t_inst_func)(t_deque *, t_deque *);

void	push_swap_mergesort(t_deque *a_deque, t_deque *b_deque);
void	push_swap_divide(t_deque *a_deque, t_deque *b_deque);
void	join_to_a(t_deque *a, t_deque *b, t_bool pos);
void	join_to_b(t_deque *a, t_deque *b, t_bool pos);

// ft_deque interface
void	pa(t_deque *a, t_deque *b);
void	pb(t_deque *a, t_deque *b);
void	sa(t_deque *a, t_deque *b);
void	sb(t_deque *a, t_deque *b);
void	ss(t_deque *a, t_deque *b);
void	ra(t_deque *a, t_deque *b);
void	rb(t_deque *a, t_deque *b);
void	rr(t_deque *a, t_deque *b);
void	rra(t_deque *a, t_deque *b);
void	rrb(t_deque *a, t_deque *b);
void	rrr(t_deque *a, t_deque *b);
void	no_inst(t_deque *a, t_deque *b);

// utility functions
t_bool	sort_cycle(t_deque *a, t_deque *b);
t_bool	sort_check(t_deque *a);
size_t	partial_check(t_node **ptr, size_t size, t_bool pos, t_bool dir);
size_t	get_blocks(t_deque *deque, t_bool dir);
void	rotate_block(t_deque *deque, t_bool which);
void	revrot_block(t_deque *deque, t_bool which);

void	print_data(t_deque *a_deque, t_deque *b_deque);
void	delete_data(t_deque *a_deque, t_deque *b_deque);

// optimizing funcions
void	join_edge(t_deque *deque, t_bool which);
void	join_deques(t_deque *a, t_deque *b);
void	inst_queue(int inst_idx);

#endif
