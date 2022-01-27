/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:59:15 by hseong            #+#    #+#             */
/*   Updated: 2022/01/27 20:35:37 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

typedef struct s_list
{
	struct s_list	*next;
	int				num;
}		t_list;

typedef struct s_meta_list
{
	t_list		*head;
	size_t		size;

}		t_meta_list;

void	mergesort_list(t_list *head);
int		push_front(t_meta_list *meta_list, int num);
int		push_back(t_meta_list *meta_list, int num);
void	pop_front(t_meta_list *meta_list);
void	pop_back(t_meta_list *meta_list);
void	print_list(t_meta_list *meta_list);

#endif
