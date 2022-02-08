/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlinkedlist_cur.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:17:56 by hseong            #+#    #+#             */
/*   Updated: 2022/02/08 20:23:01 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlinkedlist.h"

void	move_front(t_dlist *list)
{
	if (list->cur == list->head)
		return ;
	list->cur = list->cur->prev;
}

void	move_back(t_dlist *list)
{
	if (list->cur == list->tail)
		return ;
	list->cur = list->cur->next;
}
