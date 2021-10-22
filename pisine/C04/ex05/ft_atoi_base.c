/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:21:54 by hseong            #+#    #+#             */
/*   Updated: 2021/10/21 12:27:49 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		base_validity(char *base);
int		str_decode(char *str, char *base, int baselen, int strlen);
int		strlen_base(char *str, char *base);
int		ret_check(int *num, int nsign);

// loop is better?
int	ft_atoi_base(char *str, char *base)
{
	int		baselen;
	int		strlen;
	int		nsign;
	int		ret;

	baselen = base_validity(base);
	if (baselen == 1)
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		++str;
	nsign = 0;
	while (*str == '-' || *str == '+')
	{
		nsign += *str == '-';
		++str;
	}
	strlen = strlen_base(str, base);
	if (strlen == 0)
		return (0);
	ret = str_decode(str + strlen - 1, base, baselen, strlen);
	return (ret_check(&ret, nsign));
}

int	base_validity(char *base)
{
	char	repeat[96];
	int		baselen;

	baselen = 0;
	while (baselen < 96)
		repeat[baselen++] = 0;
	baselen = 0;
	while (*base != 0)
	{
		if (repeat[*base - 32])
			return (1);
		else if (*base == '+' || *base == '-') 
			return (1);
		else if (*base == 32 || (*base >= 9 && *base <= 13))
			return (1);
		else if (*base < 32 || *base == 127)
			return (1);
		repeat[*base - 32] = 1;
		++base;
		++baselen;
	}
	if (baselen < 2)
		return (1);
	return (baselen);
}

int	str_decode(char *str, char *base, int baselen, int strlen)
{
	int		order;

	if (strlen == 0)
		return (0);
	order = 0;
	while (base[order] != 0)
	{
		if (base[order] == *str)
			break ;
		++order;
	}
	return (order + baselen * str_decode(str - 1, base, baselen, strlen - 1));
}

int	strlen_base(char *str, char *base)
{
	int		strlen;
	int		str_flag;
	int		idx;

	strlen = 0;
	while (*str != 0)
	{
		idx = 0;
		str_flag = 0;
		while (base[idx] != 0)
		{
			if (base[idx] == *str)
				str_flag = 1;
			++idx;
		}
		if (str_flag == 0)
			break ;
		++strlen;
		++str;
	}
	return (strlen);
}

int	ret_check(int *ret, int nsign)
{
	if (*ret == -2147483648)
		return (-2147483648);
	else if (nsign % 2 == 1)
		return (-1 * (*ret));
	return (*ret);
}
