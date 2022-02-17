/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_dep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:11:46 by hseong            #+#    #+#             */
/*   Updated: 2022/02/08 17:42:41 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	dep_delete_item(t_item item)
{
	(void)item;
}

void	dep_print_node(t_node *node)
{
	ft_putnbr_space(node->item);
}
