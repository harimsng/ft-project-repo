/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:26:49 by hseong            #+#    #+#             */
/*   Updated: 2021/11/11 00:06:28 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*range;
	unsigned int	idx;
	unsigned int	len;

	idx = 0;
	len = ft_strlen(s);
	range = (char *)malloc(sizeof(char) * len + 1);
	if (!range)
		return (NULL);
	while (idx < len)
	{
		range[idx] = f(idx, s[idx]);
		++idx;
	}
	range[idx] = 0;
	return (range);
}
