/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 21:21:20 by hseong            #+#    #+#             */
/*   Updated: 2021/11/10 18:24:50 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int32 0A0B0C0D	> i [0A], i+1 [0B], i+2 [0C], i+3[0D]
// big endian 		: msb is at lower address.
// int32 0A0B0C0D	> i [0D], i+1 [0C], i+2 [0B], i+3[0A]
// little endian	: lsb is at lower address.
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = b;
	while (len--)
		*ptr++ = (unsigned char)c;
	return (b);
}
