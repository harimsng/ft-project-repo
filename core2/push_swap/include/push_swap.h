/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:57:01 by hseong            #+#    #+#             */
/*   Updated: 2022/02/25 21:09:29 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_deque.h"

# define INT_MIN (-2147483648LL)
# define INT_MAX (2147483647)
# define TRUE (1)
# define FALSE (0)
# define HEAD (1)
# define TAIL (0)
# define INC (1)
# define DEC (0)

typedef int	t_bool;

void	push_swap_mergesort(t_deque *a_deque, t_deque *b_deque);

typedef void	(*inst_func)(t_deque *[2]);

// ft_deque interface
void	pa(t_deque *deques[2]);
void	pb(t_deque *deques[2]);
void	sa(t_deque *deques[2]);
void	sb(t_deque *deques[2]);
void	ss(t_deque *deques[2]);
void	ra(t_deque *deques[2]);
void	rb(t_deque *deques[2]);
void	rr(t_deque *deques[2]);
void	rra(t_deque *deques[2]);
void	rrb(t_deque *deques[2]);
void	rrr(t_deque *deques[2]);
void	no_inst(t_deque *deques[2]);
// r : front to back
// rr : back to front


// utility functions
t_bool	sort_loop(t_deque *deques[2]);
t_bool	sort_check(t_deque *a);
size_t	partial_check(t_node **ptr, size_t size, t_bool pos, t_bool dir);

size_t	get_blocks(t_deque *deque, t_bool dir);
void	join_edge(t_deque *deque, t_bool which);

void	print_data(t_deque *a_deque, t_deque *b_deque);
void	delete_data(t_deque *a_deque, t_deque *b_deque);

#endif
