/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:35:42 by hseong            #+#    #+#             */
/*   Updated: 2021/11/24 20:35:43 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
