/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:57:06 by hseong            #+#    #+#             */
/*   Updated: 2022/02/09 21:51:09 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	verify_arg(char *arg, t_list *list);
static int	int_test(char **arg_ptr, t_list *list);
static int	duplicate_check(t_list *list);
t_node		*ft_lstclone(t_node *head);

int	get_list(int argc, char **argv, t_list *list)
{
	int		idx;

	idx = 1;
	if (argc == 1)
		return (1);
	while (idx < argc && verify_arg(argv[idx], list))
		++idx;
	print_dlist_forward(list);
	if (idx != argc || duplicate_check(list))
		return (0);
	return (1);
}

int	verify_arg(char *arg, t_list *list)
{
	while (int_test(&arg, list))
		++arg;
	if (list->size == 0)
		return (0);
	return (1);
}

int	int_test(char **arg_ptr, t_list *list)
{
	ssize_t		num;
	char		*arg;
	int			nsign;
	int			len;

	arg = *arg_ptr;
	len = 0;
	num = 0;
	while (*arg == ' ')
		++arg;
	nsign = *arg == '-';
	arg += nsign;
	while (*arg >= 48 && *arg < 58)
	{
		num = num * 10 + *arg++ - 48;
		++len;
	}
	num *= 1 - 2 * nsign;
	if (len > 10 || len == 0 || num < INT_MIN || num > INT_MAX
		|| (*arg != ' ' && *arg != 0))
		list->size = 0;
	else
		push_back(list, num);
	*arg_ptr = arg;
	return (*arg == ' ');
}

int	duplicate_check(t_list *list)
{
	t_node	*head;

	head = list->head;
	mergesort_dlist(list);
	while (head->next != NULL)
	{
		if (head->item == head->next->item)
			return (1);
		head = head->next;
	}
	return (0);
}
