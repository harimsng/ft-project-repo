/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejo <hyejo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:19:26 by hyejo             #+#    #+#             */
/*   Updated: 2021/10/24 13:45:06 by hyejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	is_space(char ch)
{
	if (ch == ' ' || ch == '\t' || ch == '\n'
		|| ch == '\v' || ch == '\f' || ch == '\r')
		return (1);
	return (0);
}

long long	ft_atoi(char *str)
{
	long long	sign;
	long long	result;

	sign = 1;
	result = 0;
	while (is_space(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	if (*str == '.')
		return (-1);
	return (sign * result);
}
