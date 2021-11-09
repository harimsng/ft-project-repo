/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:37:12 by hseong            #+#    #+#             */
/*   Updated: 2021/11/09 18:53:30 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c);

int	ft_atoi(const char *str)
{
	int		ret;
	int		neg;

	while (ft_isspace(*str))
		++str;
	neg = *str == '-';
	str += (neg || *str == '+');
	ret = 0;
	while (ft_isdigit(*str))
		ret = 10 * ret + *str++ - 48;
	return (ret * (1 - 2 * neg));
}

static int	ft_isspace(int c)
{
	if ((c > 8 && c < 14) || c == 32)
		return (1);
	return (0);
}
