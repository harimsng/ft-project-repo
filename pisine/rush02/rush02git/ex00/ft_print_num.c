/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejo <hyejo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:21:43 by hyejo             #+#    #+#             */
/*   Updated: 2021/10/24 13:09:31 by hyejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_print_num(long long num, t_dicts dicts)
{
	t_dict	dict;
	int		i;

	i = 0;
	while (i < dicts.size)
	{
		dict = dicts.dicts[i++];
		if ((dict.num && num / dict.num) || num == dict.num)
		{
			if (dict.num && (num / dict.num != 1 || num >= 100))
			{
				ft_print_num(num / dict.num, dicts);
				write(1, " ", 1);
			}
			ft_putstr(dict.name);
			if (dict.num && num % dict.num)
			{
				write(1, " ", 1);
				ft_print_num(num % dict.num, dicts);
			}
			return ;
		}
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}
