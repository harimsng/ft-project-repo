/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:16:56 by hseong            #+#    #+#             */
/*   Updated: 2022/03/23 18:23:26 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_type.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	len = 0;
	while (s[len])
		++len;
	write(fd, s, len);
}

void	ft_swap_points(t_point **p0, t_point **p1)
{
	t_point	*temp;

	temp = *p0;
	*p0 = *p1;
	*p1 = temp;
}

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

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

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dst;
	s = src;
	while (len--)
		*d++ = *s++;
	return (dst);
}
