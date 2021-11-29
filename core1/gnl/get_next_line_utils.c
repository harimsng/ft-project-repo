/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 22:35:53 by hseong            #+#    #+#             */
/*   Updated: 2021/11/29 17:00:47 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void	*dest, const void *src, size_t size)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	while (size--)
		*d++ = *s++;
	return (dest);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*ret;
	unsigned char	*ptr;

	size *= count;
	ret = malloc(size);
	if (!ret)
		return (NULL);
	ptr = (unsigned char *)ret;
	while (size--)
		*ptr++ = 0;
	return (ret);
}	
