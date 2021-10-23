/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:49:25 by hseong            #+#    #+#             */
/*   Updated: 2021/10/23 19:49:52 by hseong           ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strndup(char *str, unsigned int size)
{
	unsigned int	idx;
	char			*ret;

	idx = 0;
	while (str[idx] && idx < size)
		++idx;
	size = idx;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (0);
	idx = 0;
	while (idx < size)
	{
		ret[idx] = str[idx];
		++idx;
	}
	ret[idx] = 0;
	return (ret);
}
