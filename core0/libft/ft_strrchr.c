/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:03:33 by hseong            #+#    #+#             */
/*   Updated: 2021/11/11 03:10:02 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// should check manual
char	*ft_strrchr(const char *s, int c)
{
	char	*ret;

	if (c < -128 || c > 127 || c == -1)
		return (NULL);
	ret = NULL;
	while (*s)
	{
		if (*s == c)
			ret = (char *)s;
		++s;
	}
	if (!c)
		ret = (char *)s;
	return (ret);
}
