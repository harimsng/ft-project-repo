/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublyll.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:48:54 by hseong            #+#    #+#             */
/*   Updated: 2022/02/08 19:05:45 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLYLL_H
# define DOUBLYLL_H

# include <unistd.h>
# include <stdlib.h>

typedef int		t_item;

typedef struct s_node
{
	t_item			item;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_doublyll
{
	t_node		*head;
	t_node		*tail;
	t_node		*cur;
	size_t		size;

}				t_doublyll;

// CREATE AND DELETE
int		push_front(t_doublyll *list, t_item item);
int		push_back(t_doublyll *list, t_item item);
void	pop_front(t_doublyll *list);
void	pop_back(t_doublyll *list);

// UPDATE
void	move_front(t_doublyll *list);
void	move_back(t_doublyll *list);

// READ
void	print_node(t_node *node);
void	print_list_foward(t_doublyll *list);
void	print_list_backward(t_doublyll *list);

// utils
void	ft_putnbr_space(int num);
void	mergesort_doublyll(t_doublyll *list);

// depends on specification
void	dep_delete_item(t_item item);
void	dep_print_node(t_node *node);

#endif
