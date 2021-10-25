/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:31:50 by hseong            #+#    #+#             */
/*   Updated: 2021/10/25 21:27:42 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"
#include "../includes/ft_op.h"

typedef long long	(*t_operator)(long long, long long);

static const char	g_operators[5] = "+-*/%";
// g_operators[5] is not NULL!!!

int					error_check(long long b, int idx, char op);

int	main(int argc, char **argv)
{
	int			idx;
	long long	a;
	long long	b;
	t_operator	g_op_arr[5];

	g_op_arr[0] = ft_long_add;
	g_op_arr[1] = ft_long_sub;
	g_op_arr[2] = ft_long_mul;
	g_op_arr[3] = ft_long_div;
	g_op_arr[4] = ft_long_mod;
	if (argc != 4)
		return (0);
	idx = 0;
	while (idx < 5 && (argv[2][0] != g_operators[idx]))
		++idx;
	a = ft_atol(argv[1]);
	b = ft_atol(argv[3]);
	if (error_check(b, idx, argv[2][1]))
		return (0);
	ft_ltoa(g_op_arr[idx](a, b));
	ft_putstr("\n");
	return (0);
}

int	error_check(long long b, int idx, char op)
{
	if (idx == 5 || op != 0)
	{
		ft_putstr("0\n");
		return (1);
	}
	else if (idx == 3 && b == 0)
	{
		ft_putstr("Stop : division by zero\n");
		return (1);
	}
	else if (idx == 4 && b == 0)
	{
		ft_putstr("Stop : modulo by zero\n");
		return (1);
	}
	return (0);
}
