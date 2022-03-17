/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:14:22 by hseong            #+#    #+#             */
/*   Updated: 2022/03/17 16:18:45 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(const char *str)
{
	size_t		len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t		ret;

	ret = 0;
	while (src[ret])
		++ret;
	if (!size)
		return (ret);
	while (*src && size - 1)
	{
		*dest++ = *src++;
		--size;
	}
	*dest = 0;
	return (ret);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		ret;

	ret = 0;
	while (src[ret])
		++ret;
	if (!size)
		return (ret);
	while (*dest && size)
	{
		++ret;
		++dest;
		--size;
	}
	if (!size)
		return (ret);
	while (*src && size - 1)
	{
		*dest++ = *src++;
		--size;
	}
	*dest = 0;
	return (ret);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while (--n && *s1 && *s2 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
