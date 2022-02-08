/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:59:15 by hseong            #+#    #+#             */
/*   Updated: 2022/02/07 21:51:22 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

typedef struct s_node
{
	int				num;
	struct s_node	*next;
}		t_node;

typedef struct s_list
{
	t_node		*head;
	size_t		size;

}		t_list;

void	mergesort_list(t_node **head);
int		push_front(t_list *list, int num);
int		push_back(t_list *list, int num);
void	pop_front(t_list *list);
void	pop_back(t_list *list);
void	print_list(t_node *node);

#endif
