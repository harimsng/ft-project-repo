/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:32:02 by hseong            #+#    #+#             */
/*   Updated: 2021/11/11 03:40:34 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// should check manual
char	*ft_strchr(const char *s, int c)
{
	if (c < -128 || c > 127 || c == -1)
		return (NULL);
	while (*s && *s != c)
		++s;
	if (*s != c)
		return (NULL);
	return ((char *)s);
}
