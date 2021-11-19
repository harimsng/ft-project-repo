/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 22:35:53 by hseong            #+#    #+#             */
/*   Updated: 2021/11/19 22:30:29 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	size_t		len;
	char		*ret;

	len = ft_strlen(s);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	while (*s)
		*ret++ = *s++;
	*ret = 0;
	return (ret - len);
}

void	*ft_memset(void *addr, int c, size_t size)
{
	unsigned char	*itr;

	itr = addr;
	while (size--)
		*itr++ = (unsigned char)c;
	return (addr);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t		ret;

	ret = 0;
	while (src[ret])
		++ret;
	if (!size)
		return (ret);
	while (--size && *src)
		*dest++ = *src++;
	*dest = 0;
	return (ret);
}

size_t	ft_strlen(const char *s)
{
	size_t		ret;

	ret = 0;
	while (s[ret])
		++ret;
	return (ret);
}
