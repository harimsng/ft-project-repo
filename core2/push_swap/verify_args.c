/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:57:06 by hseong            #+#    #+#             */
/*   Updated: 2022/01/26 20:44:22 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_list(int argc, char **argv, t_meta_list *meta_list)
{
	int		idx;

	idx = 1;
	while (idx < argc && verify_arg(argv[idx], meta_list))
		++idx;
	if (idx != argc)
		return (0);
	return (1);
}

int	verify_arg(char *arg, t_meta_list *meta_list)
{
	char	*arg_end;
	char	*arg_start;

	while (int_test(&arg, meta_list))
		++arg;
	if (meta_list->size == 0)
		return (0);
	return (1);
}

int	int_test(char *arg, t_meta_list *meta_list)
{
	ssize_t		num;
	int			nsign;
	int			len;

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
	if (len > 10 || len == 0
		|| num < INT_MIN || num > INT_MAX
		|| (*arg != ' ' && *arg != 0))
	{
		meta_list->size = 0;
		return (0);
	}
	push_front(meta_list, num);
	return (*arg == ' ');
}
