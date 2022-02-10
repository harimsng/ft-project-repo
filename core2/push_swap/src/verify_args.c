/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:57:06 by hseong            #+#    #+#             */
/*   Updated: 2022/02/10 18:19:07 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	verify_arg(char *arg, t_deque *deque);
static int	int_test(char **arg_ptr, t_deque *deque);
static int	duplicate_check(t_deque *deque);

int	get_list(int argc, char **argv, t_deque *deque)
{
	int		idx;

	idx = 1;
	if (argc == 1)
		return (1);
	while (idx < argc && verify_arg(argv[idx], deque))
		++idx;
	if (idx != argc || duplicate_check(deque))
		return (0);
	return (1);
}

int	verify_arg(char *arg, t_deque *deque)
{
	while (int_test(&arg, deque))
		++arg;
	if (deque->size == 0)
		return (0);
	return (1);
}

int	int_test(char **arg_ptr, t_deque *deque)
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
		deque->size = 0;
	else
		push_back(deque, num);
	*arg_ptr = arg;
	return (*arg == ' ');
}

int	duplicate_check(t_deque *deque)
{
	t_node	*head;

	mergesort_dlist(deque);
	head = deque->head;
	while (head->next != NULL)
	{
		if (head->item == head->next->item)
			return (1);
		head = head->next;
	}
	return (0);
}
