/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:37:12 by hseong            #+#    #+#             */
/*   Updated: 2022/04/26 04:01:46 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LLONG_MAX
# define LLONG_MAX 9223372036854775807LL
#endif

static int	ft_isspace(int c);
static int	ft_isdigit(int c);

int	ft_atoi(const char *str)
{
	unsigned long long	num;
	unsigned long long	temp;
	int					ret;
	int					neg;

	while (ft_isspace(*str))
		++str;
	neg = *str == '-';
	str += (neg || *str == '+');
	num = 0;
	temp = 0;
	while (ft_isdigit(*str) && temp <= num)
	{
		temp = num;
		num = 10 * num + *str++ - 48;
	}
	if (temp > num || num > LLONG_MAX)
		return ((int)(LLONG_MAX * !neg + (-LLONG_MAX - 1) * neg));
	ret = (1 - 2 * neg) * ((int)num);
	return (ret);
}

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
