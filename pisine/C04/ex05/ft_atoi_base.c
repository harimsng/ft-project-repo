/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:21:54 by hseong            #+#    #+#             */
/*   Updated: 2021/10/13 19:21:59 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		base_validity(char *base);
int		str_decode(char *str, char *base, int base_len, int str_len);

int	ft_atoi_base(char *str, char *base)
{
	int		base_len;
	int		str_len;

	str_len = 0;
	while (str[str_len] != 0)
		++str_len;
	base_len = base_validity(base);
	return (str_decode(str + str_len - 1, base, base_len, str_len));
}

int	base_validity(char *base)
{
	char	repeat[96];
	int		base_len;

	base_len = 0;
	while (base_len < 96)
		repeat[base_len++] = 0;
	base_len = 0;
	while (*base != 0)
	{
		if (repeat[*base - 32])
			return (1);
		else if (*base == '+' || *base == '-')
			return (1);
		repeat[*base - 32] = 1;
		++base;
		++base_len;
	}
	if (base_len < 2)
		return (1);
	return (base_len);
}

int	str_decode(char *str, char *base, int base_len, int str_len)
{
	int		num;

	if (str_len == 0)
		return (0);
	num = 0;
	while (base[num] != 0)
	{
		if (base[num] == *str)
			break ;
		++num;
	}
	return (num + base_len * str_decode(str - 1, base, base_len, str_len - 1));
}
