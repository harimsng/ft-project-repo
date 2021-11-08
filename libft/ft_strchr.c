/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:32:02 by hseong            #+#    #+#             */
/*   Updated: 2021/11/08 21:03:59 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// need manual
char	*ft_strchr(const char *s, int c)
{
	char	cha;

	cha = (char)c;
	while (*s && *s != cha)
		++s;
	if (*s != (char)cha)
		return (NULL);
	return ((char*)s);
}
