/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:29:06 by hseong            #+#    #+#             */
/*   Updated: 2021/11/10 22:18:06 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*ret;
	size_t		right;
	size_t		left;

	right = 0;
	left = 0;
	while (s1[right])
	{
		if (ft_strchr(set, s1[right++]))
			continue ;
		++left;
	}
	ret = (char *)malloc(sizeof(char) * (left + 1));
	if (!ret)
		return (NULL);
	ret[left] = 0;
	right = 0;
	left = 0;
	while (s1[right])
	{
		if (ft_strchr(set, s1[right++]))
			continue ;
		ret[left++] = s1[right - 1];
	}
	return (ret);
}
