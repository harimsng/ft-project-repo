/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:10:14 by hseong            #+#    #+#             */
/*   Updated: 2021/10/19 15:15:47 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdio.h>
int		base_validity(char *base);
int		str_check(char *str, char *base_from);
int		str_decode(char *nbr, char *base_from, int bf_len, int str_len);
char	*str_encode(int num, char *base_to, int bt_len, int nsign);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nsign;
	int		bf_len;
	int		bt_len;
	int		str_len;
	int		num;

	if (nbr == (void *)0 || base_from == (void *)0 || base_to == (void *)0)
		return ((void *)0);
	while ((*nbr > 8 && *nbr < 14) || *nbr == 32)
		++nbr;
	nsign = 0;
	while (*nbr == '-' || *nbr == '+')
		nsign += (*(nbr++) == '-');
	bf_len = base_validity(base_from);
	bt_len = base_validity(base_to);
	if (bf_len == 1 || bt_len == 1)
		return ((void *)0);
	str_len = str_check(nbr, base_from);
	num = str_decode(nbr + str_len - 1, base_from, bf_len, str_len);
	printf("%d\n", num);
	return (str_encode(num, base_to, bt_len, nsign));
}

int	base_validity(char *base)
{
	char	table[96];
	int		idx;
	int		len;

	len = 0;
	idx = 0;
	while (idx < 96)
		table[idx++] = 0;
	while (*base)
	{
		if (*base == '-' || *base == '+' || *base == ' ')
			return (1);
		else if (table[*base - 32])
			return (1);
		table[*base - 32] = 1;
		++base;
		++len;
	}
	return (len);
}

int	str_decode(char *nbr, char *base_from, int bf_len, int str_len)
{
	int		num;

	if (str_len == 0)
		return (0);
	num = 0;
	while (base_from[num])
	{
		if (base_from[num] == *nbr)
			break ;
		++num;
	}
	
	return (num + bf_len * str_decode(nbr - 1, base_from, bf_len, str_len - 1));
}

int str_check(char *str, char *base_from)
{
	int		ret;
	int		idx;
	int		base_flag;

	ret = 0;
	while (str[ret])
	{
		base_flag = 0;
		idx = 0;
		while (base_from[idx])
		{
			if (base_from[idx] == str[ret])
				base_flag = 1;
			++idx;
		}
		if (!base_flag)
			return (ret);
		++ret;
	}
	return (ret);
}
