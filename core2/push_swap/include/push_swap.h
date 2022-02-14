/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:57:01 by hseong            #+#    #+#             */
/*   Updated: 2022/02/14 20:25:55 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "ft_deque.h"

#include "ft_debug.h"

# define INT_MIN (-2147483648LL)
# define INT_MAX (2147483647)
# define TRUE (1)
# define FALSE (0)

typedef int	t_bool;

int		get_list(int argc, char **argv, t_deque *deque);
int		print_error(void);
void	push_swap(t_deque *a_deque, t_deque *b_deque);

void	pa(t_deque *a, t_deque *b);
void	pb(t_deque *b, t_deque *a);
void	sa(t_deque *a);
void	sb(t_deque *b);
void	ss(t_deque *a, t_deque *b);
void	ra(t_deque *a);
void	rb(t_deque *b);
void	rr(t_deque *a, t_deque *b);
void	rra(t_deque *a);
void	rrb(t_deque *b);
void	rrr(t_deque *a, t_deque *b);

t_bool	sort_loop(t_deque *a, t_deque *b);
t_bool	sort_check(t_deque *a);

void	print_data(t_deque *a_deque, t_deque *b_deque);
void	delete_data(t_deque *a_deque, t_deque *b_deque);

#endif
