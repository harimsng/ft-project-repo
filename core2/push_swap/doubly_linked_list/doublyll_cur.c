/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublyll_cur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:20:13 by hseong            #+#    #+#             */
/*   Updated: 2022/02/08 17:26:37 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doublyll.h"

void	move_front(t_doublyll *list)
{
	if (list->cur == list->head)
		return ;
	list->cur = list->cur->prev;
}

void	move_back(t_doublyll *list)
{
	if (list->cur == list->tail)
		return ;
	list->cur = list->cur->next;
}
