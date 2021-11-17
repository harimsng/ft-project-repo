/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejo <hyejo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:21:43 by hyejo             #+#    #+#             */
/*   Updated: 2021/10/24 16:29:54 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dict.h"
#include "../includes/ft.h"

void	ft_print_num(long long num, t_dict *dict_arr, int dict_size)
{
	t_dict		dict;
	int			i;

	i = 0;
	while (i < dict_size)
	{
		dict = dict_arr[i];
		if ((dict.key && num / dict.key) || num == dict.key)
		{
			if (dict.key && (num / dict.key != 1 || num >= 100))
			{
				ft_print_num(num / dict.key, dicts);
				write(1, " ", 1);
			}
			ft_putstr(dict.value);
			if (dict.key && num % dict.key)
			{
				write(1, " ", 1);
				ft_print_num(num % dict.key, dicts);
			}
			return ;
		}
	}
}
