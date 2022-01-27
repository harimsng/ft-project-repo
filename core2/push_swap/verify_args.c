/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:57:06 by hseong            #+#    #+#             */
/*   Updated: 2022/01/27 20:40:27 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	verify_arg(char *arg, t_meta_list *meta_list);
static int	int_test(char **arg_ptr, t_meta_list *meta_list);
static int	duplicate_check(t_meta_list *meta_list);
t_list		*ft_lstclone(t_list *head);

int	get_list(int argc, char **argv, t_meta_list *meta_list)
{
	int		idx;

	idx = 1;
	while (idx < argc && verify_arg(argv[idx], meta_list))
		++idx;
	print_list(meta_list);
	if (idx != argc || duplicate_check(meta_list))
		return (0);
	return (1);
}

int	verify_arg(char *arg, t_meta_list *meta_list)
{
	while (int_test(&arg, meta_list))
		++arg;
	if (meta_list->size == 0)
		return (0);
	return (1);
}

int	int_test(char **arg_ptr, t_meta_list *meta_list)
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
		meta_list->size = 0;
	else
		push_back(meta_list, num);
	*arg_ptr = arg;
	return (*arg == ' ');
}

int	duplicate_check(t_meta_list *meta_list)
{
	t_list	*head;

	head = meta_list->head;
	mergesort_list(head);
	while (head->next != NULL)
	{
		if (head->num == head->next->num)
			return (1);
		head = head->next;
	}
	return (0);
}
