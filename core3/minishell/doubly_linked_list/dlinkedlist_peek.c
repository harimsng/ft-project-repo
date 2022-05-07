/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlinkedlist_peek.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 06:51:51 by hseong            #+#    #+#             */
/*   Updated: 2022/05/08 06:54:27 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlinkedlist.h"

t_item	*peek_front(t_dlist *list)
{
	if (list->size == 0)
		return (EMPTY_ITEM);
	return (list->head);
}

t_item	*peek_back(t_dlist *list)
{
}
