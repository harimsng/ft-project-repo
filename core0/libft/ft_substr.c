/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:24:15 by hseong            #+#    #+#             */
/*   Updated: 2021/11/08 20:19:44 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ret;
	size_t		idx;

	if (!s || ft_strlen(s) < start)
		return (NULL);
	len -= (ft_strlen(s) < start + len) * (ft_strlen(s) - start - len);
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (!ret)
		return (NULL);
	idx = 0;
	while (idx < len)
	{
		ret[idx] = s[start + idx];
		++idx;
	}
	ret[idx] = 0;
	return (ret);
}
