/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:39:10 by hseong            #+#    #+#             */
/*   Updated: 2021/11/10 18:28:45 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 0000 0111 1111 1111 = 1023 + 1024
// 0000 0001 1111 1111 = 1023 - 512
// check what is proper return value(-1, 0, 1 or diff, 0)
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	if (!n)
		return (0);
	str1 = s1;
	str2 = s2;
	while (--n && *str1 == *str2)
	{
		++str1;
		++str2;
	}
	return (*str1 - *str2);
}
