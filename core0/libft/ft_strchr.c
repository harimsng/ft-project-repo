/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:32:02 by hseong            #+#    #+#             */
/*   Updated: 2021/11/17 15:57:59 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// different with linux.
char	*ft_strchr(const char *s, int c)
{
	if (c == -1)
		return (NULL);
	while (*s && *s != (char)c)
		++s;
	if (*s != (char)c)
		return (NULL);
	return ((char *)s);
}
