/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:59:15 by hseong            #+#    #+#             */
/*   Updated: 2022/02/08 18:18:17 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include <unistd.h>
# include <stdlib.h>

typedef int		t_item;

typedef struct s_node
{
	t_item			item;
	struct s_node	*next;
}				t_node;

typedef struct s_list
{
	t_node		*head;
	size_t		size;
}				t_list;

// CREATE AND DELETE
int			push_front(t_list *list, t_item item);
int			push_back(t_list *list, t_item item);
void		pop_front(t_list *list);
void		pop_back(t_list *list);

// READ
void		print_node(t_node *node);
void		print_list(t_list *list);

// utils
void		ft_putnbr_space(int num);
void		mergesort_list(t_list *list);

// depends on specification
void		dep_delete_item(t_item item);
void		dep_print_node(t_node *node);

#endif
