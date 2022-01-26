/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:57:01 by hseong            #+#    #+#             */
/*   Updated: 2022/01/26 21:14:50 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "linked_list.h"

#include "ft_debug.h"

# define INT_MIN (-2147483648LL)
# define INT_MAX (2147483647)

int		get_list(int argc, char **argv, t_meta_list *meta_list);
int		print_error();
void	push_swap(t_meta_list *meta_list);

#endif
