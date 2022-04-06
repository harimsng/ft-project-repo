/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:37:12 by hseong            #+#    #+#             */
/*   Updated: 2022/04/06 20:40:10 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LONG_MAX (9223372036854775807LL)

static int	ft_isdigit(int c);
static int	ft_isspace(int c);

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
	if (temp > num || num > LONG_MAX)
		return ((int)(LONG_MAX * !neg + (-LONG_MAX - 1) * neg));
	ret = (1 - 2 * neg) * ((int)num);
	return (ret);
}

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int	ft_isspace(int c)
{
	if ((c > 8 && c < 14) || c == 32)
		return (1);
	return (0);
}
