/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:30:30 by hseong            #+#    #+#             */
/*   Updated: 2021/10/21 13:21:57 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_stock_str.h"

void *ft_print_memory(void *addr, unsigned int size);
int					ft_strlen(char *str);
unsigned int		ft_strlcpy(char *dest, char *src, unsigned int size);

// WARNING!!
// sizeof(t_stock_str) != sizeof(int) + 2 * sizeof(char *)
// keep PADDING in mind 
t_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			idx;
	t_stock_str	*ret;

	ret = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (!ret || !av || !*av)
		return (0);
	ret[ac].str = 0;
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
		++idx;
	}
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
