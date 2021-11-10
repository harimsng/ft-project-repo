/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:43:49 by hseong            #+#    #+#             */
/*   Updated: 2021/11/10 20:04:07 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_revmemcpy(void *dst, const void *src, size_t len);

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst < src)
		ft_memcpy(dst, src, len);
	else if (dst > src)
		ft_revmemcpy(dst, src, len);
	return (dst);
}

static void	*ft_revmemcpy(void *dst, const void *src, size_t len)
{
	const unsigned char	*s;
	unsigned char		*d;

	s = src;
	d = dst;
	while (len)
	{
		d[len] = s[len];
		--len;
	}
	return (dst);
}
