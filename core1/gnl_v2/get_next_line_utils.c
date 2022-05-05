/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:27:14 by hseong            #+#    #+#             */
/*   Updated: 2022/04/30 09:40:02 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t len)
{
	size_t		ret;

	ret = 0;
	while (src[ret])
		++ret;
	if (len == 0)
		return (ret);
	--len;
	while (len && *src)
	{
		*dst++ = *src++;
		--len;
	}
	*dst = 0;
	return (ret);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	var;
	size_t			idx;

	var = (unsigned char)c;
	ptr = (unsigned char *)b;
	while (idx < len)
	{
		*ptr++ = var;
		++idx;
	}
	return (b);
}

void	hashtab_free(t_data **hashtab, int fd)
{
	t_data	*node;

	node = *hashtab;
	while (node != NULL && node->fd != fd)
		node = node->next;

}
