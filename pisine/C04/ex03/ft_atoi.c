/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:21:44 by hseong            #+#    #+#             */
/*   Updated: 2021/10/13 19:21:49 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	edge_check(char *str);

int	ft_atoi(char *str)
{
	int		nsign;
	int		ret;

	while ((*str > 8 && *str < 14) || *str == 32)
		++str;
	nsign = 0;
	while (*str == '+' || *str == '-')
	{
		nsign += *str == '-';
		++str;
	}
	ret = 0;
	if (edge_check(str))
		return (-2147483648);
	while (*str >= 48 && *str < 58)
	{
		ret *= 10;
		ret += *str - '0';
		++str;
	}
	if (nsign % 2 == 1)
		ret *= -1;
	return (ret);
}

int	edge_check(char *str)
{
	int		idx;
	char	*int_min;

	idx = 0;
	int_min = "2147483648";
	while (idx < 10 && str[idx] == int_min[idx])
		++idx;
	if (idx == 10)
		return (1);
	return (0);
}
