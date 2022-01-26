/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:57:01 by hseong            #+#    #+#             */
/*   Updated: 2022/01/26 21:00:51 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "linked_list.h"

// DEBUG
#include <stdio.h>
#define DEBUG(M, ...) printf("%s:%s:%d[" M "]\n",\
		__FILE__, __func__, __LINE__, ##__VA_ARGS__)

#define INT_MIN (-2147483648LL)
#define INT_MAX (2147483647)

int		get_list(int argc, char **argv, t_meta_list *meta_list);
int		print_error();
void	push_swap(t_meta_list *meta_list);

#endif
