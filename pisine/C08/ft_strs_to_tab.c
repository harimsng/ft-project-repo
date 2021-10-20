/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:30:30 by hseong            #+#    #+#             */
/*   Updated: 2021/10/20 20:03:56 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <stdio.h>
#include <stdio.h>

#include "ft_stock_str.h"

static const int	g_stocksize = (sizeof(int) + sizeof(char *) * 2);

void *ft_print_memory(void *addr, unsigned int size);
int					ft_strlen(char *str);
unsigned int		ft_strlcpy(char *dest, char *src, unsigned int size);

// very weird behavior happens.
// ret[ac].str is assigned with null,
// but it becomes corrupted during the while loop.
t_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			idx;
	t_stock_str	*ret;

	ret = (t_stock_str *)malloc((ac + 1) * g_stocksize);
	ft_print_memory(ret, 121);
	if (!ret || !av || !*av)
		return (0);
	ret[ac].str = 0;
	ft_print_memory(ret, 121);
	printf("%p should be null\n", ret[ac].str);
	if (ac == 0)
		return (ret);
	idx = 0;
	while (idx < ac)
	{
		ret[idx].str = av[idx];
		ret[idx].size = ft_strlen(av[idx]);
		ret[idx].copy = (char *)malloc(sizeof(char) * (ret[idx].size + 1));
		if (!ret[idx].copy)
			return (0);
		ft_strlcpy(ret[idx].copy, av[idx], ret[idx].size + 1);
		printf("%p\n", ret[idx].str);
		printf("%p should be null\n", ret[ac].str);
		++idx;
	}
	printf("%p should be null\n", ret[ac].str);
	return (ret);
}

int	ft_strlen(char *str)
{
	int		ret;

	if (!str)
		return (0);
	ret = 0;
	while (str[ret])
		++ret;
	return (ret);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	ret;
	unsigned int	idx;

	ret = 0;
	while (src[ret])
		++ret;
	idx = 0;
	while (*src && idx < size - 1)
	{
		*dest = *src;
		++dest;
		++src;
		++idx;
	}
	*dest = 0;
	return (ret + idx);
}
