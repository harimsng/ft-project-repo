/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlinkedlist.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:19:18 by hseong            #+#    #+#             */
/*   Updated: 2022/02/09 21:47:01 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLINKEDLIST_H
# define DLINKEDLIST_H

# include <unistd.h>
# include <stdlib.h>

typedef int		t_item;

typedef struct s_node
{
	t_item			item;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_dlist
{
	t_node		*head;
	t_node		*tail;
	t_node		*cur;
	size_t		size;

}				t_dlist;

// CREATE AND DELETE
int		push_front(t_dlist *list, t_item item);
int		push_back(t_dlist *list, t_item item);
t_item	pop_front(t_dlist *list);
t_item	pop_back(t_dlist *list);

// UPDATE cur
void	move_front(t_dlist *list);
void	move_back(t_dlist *list);

// READ
void	print_node(t_node *node);
void	print_dlist_forward(t_dlist *list);
void	print_dlist_backward(t_dlist *list);

// utils
void	ft_putnbr_space(int num);
void	mergesort_dlist(t_dlist *list);

// depends on specification
void	dep_delete_item(t_item item);
void	dep_print_node(t_node *node);

#endif
