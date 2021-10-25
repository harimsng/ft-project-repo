/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:31:50 by hseong            #+#    #+#             */
/*   Updated: 2021/10/25 20:32:20 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"
#include "../includes/ft_op.h"

typedef long long			t_operators(long long, long long);

static const char			g_operators[5] = "+-*/%";
static const t_operators	g_op_arr[5] = {ft_long_sum, ft_long_sub
	, ft_long_mul, ft_long_div, ft_long_mod};

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	

	return (0);
}
