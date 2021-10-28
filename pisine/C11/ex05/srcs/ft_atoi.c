/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:31:47 by hseong            #+#    #+#             */
/*   Updated: 2021/10/28 12:56:39 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	ret;
	int			nsign;
	int			len;

	while (*str == 32 || (*str >= 9 && *str <= 13))
		++str;
	nsign = 0;
	while (*str == '+' || *str == '-')
		nsign += (*str++ == '-');
	len = 0;
	while (str[len] >= '0' && str[len] <= '9')
		++len;
	ret = 0;
	while (len-- > 0)
		ret = ret * 10 + (*str++ - '0');
	return (ret * (1 + (-2) * (nsign % 2 == 1)));
}
