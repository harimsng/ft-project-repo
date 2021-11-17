/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:30:30 by hseong            #+#    #+#             */
/*   Updated: 2021/10/24 20:00:45 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dict.h"
#include "../includes/ft.h"

char	*get_value(char *str, unsigned int *value_len);

// WARNING!!
// sizeof(t_stock_str) != sizeof(int) + 2 * sizeof(char *)
// keep PADDING in mind 
t_dict	*ft_strs_to_tab(int size, char **strs)
{
	int				idx;
	unsigned int	value_len;
	t_dict			*ret;

	ret = (t_dict *)malloc((size + 1) * sizeof(t_dict));
	if (!ret || !strs || !*strs)
		return (0);
	ret[size].value = 0;
	if (size == 0)
		return (ret);
	idx = 0;
	while (idx < size)
	{
		ret[idx].key = (unsigned int)ft_atou(strs[idx]);
		ret[idx].value = get_value(strs[idx], &value_len);
		ret[idx].value = ft_strndup(ret[idx].value, (unsigned int)value_len);
		free(strs[idx]);
		++idx;
	}
	free(strs);
	return (ret);
}
// !*(ret[idx].value)	> empty value, key = -1 (invalid key)

char	*get_value(char *str, unsigned int *value_len)
{
	char		*end;
	char		*delim;

	while (*str && *str != ':')
		++str;
	delim = str++;
	while (*str && *str == ' ')
		++str;
	end = str;
	while (*end && *end != '\n')
		++end;
	--end;
	while (*end && *end == ' ')
		--end;
	if (end >= str && end != delim)
		*value_len = end - str + 1;
	else
		return (0);
	return (str);
}
