/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlinkedlist_dep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:18:02 by hseong            #+#    #+#             */
/*   Updated: 2022/02/08 20:23:04 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlinkedlist.h"

void	dep_delete_item(t_item item)
{
	(void)item;
}

void	dep_print_node(t_node *node)
{
	ft_putnbr_space(node->item);
}
