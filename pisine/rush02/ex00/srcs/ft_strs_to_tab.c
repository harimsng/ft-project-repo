/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:30:30 by hseong            #+#    #+#             */
/*   Updated: 2021/10/23 20:01:36 by hseong           ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dict.h"
#include "../includes/ft.h"

char	*get_value(char *str);

// WARNING!!
// sizeof(t_stock_str) != sizeof(int) + 2 * sizeof(char *)
// keep PADDING in mind 
t_dict	*ft_strs_to_tab(int size, char **strs)
{
	int			idx;
	t_dict		*ret;

	ret = (t_dict *)malloc((size + 1) * sizeof(t_dict));
	if (!ret || !strs || !*strs)
		return (0);
	ret[size].value = 0;
	if (size == 0)
		return (ret);
	idx = 0;
	while (idx < size)
	{
		ret[idx].key = ft_atou(strs[idx]);
		ret[idx].value = get_value(strs[idx]);
		if (!*(ret[idx].value))
			ret[idx].key = -1;
		++idx;
	}
	return (ret);
}

char *get_value(char *str)
{
	while (*str && *str != ':')
		++str;
	++str;
	while (*str && *str == ' ')
		++str;
	return (str);
}
