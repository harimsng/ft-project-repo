/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 18:35:47 by hseong            #+#    #+#             */
/*   Updated: 2021/10/23 21:12:13 by hseong           ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

// which one we should use between ft_atoi and atoi?
long long int	ft_atou(char *str)
{
	int					idx;
	long long unsigned	ret;

	idx = 0;
	while (*str && ((*str >= 9 && *str <= 13) || *str == 32))
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			return (-1);
		++str;
	}
	idx = 0;
	while (str[idx] && str[idx] >= '0' && str[idx] <= '9')
	{
		++idx;
		if (idx > 10)
			return (-1);
	}
	ret = 0;
	while (idx-- > 0)
		ret = ret * 10 + *str++ - '0';
	return (long long int)(ret * (ret <= 4294967295) + -1 * (ret > 4294967295));
}
/*  ft_atoi
	while (*str && (*str == '+' || *str == '-'))
	{
		idx += (*str == '-');
		++str;
	}
*/
