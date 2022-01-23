/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:27:14 by hseong            #+#    #+#             */
/*   Updated: 2022/01/21 21:49:02 by hseong           ###   ########.fr       */
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

int	storage_chaining(t_data *storage, t_buf *buf, int fd)
{
	while (storage->next != NULL)
		storage = storage->next;
	storage->next = malloc(sizeof(t_data));
	if (storage->next == 0)
		return (1);
	storage = storage->next;
	storage->next = NULL;
	storage->fd = buf->fd;
	storage->size = buf->size;
	ft_strlcpy(storage->str, buf->str, buf->size);
	return (0);
}

void	storage_free(t_data **storage, int fd)
{
	t_data	*node;

	node_ptr = *storage;
	while (node != NULL && node->fd != fd)
		node = node->next;
	
}
