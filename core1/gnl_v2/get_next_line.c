/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 21:14:13 by hseong            #+#    #+#             */
/*   Updated: 2022/01/21 21:49:05 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	fd_load(t_data *storage, t_buf *buf, int fd);
void	fd_save(t_data *storage, t_buf *buf, int fd);
int		fd_find(t_data **storage, int fd);
int		eol_check(t_buf *buf);

char	*get_next_line(int fd)
{
	static t_data	storage[1024];
	t_buf			buf;
	char			*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	fd_load(storage + fd % 1024, &buf, fd);
	buf.size += read(fd, buf + buf.size, BUFFER_SIZE - buf.size);
	while (!eol_check(buf))
		buf.size = read(fd, buf, BUFFER_SIZE);
	if (buf.size != BUFFER_SIZE)
		fd_save(storage + fd % 1024, &buf, fd);
	ft_strlcpy(line, buf.str, buf.size);
	return (line);
}

void	fd_save(t_data *storage, t_buf *buf, int fd)
{
	if (buf->size == 0 || buf->str[buf->size - 1] == 0)
		storage_free(&storage, fd);
	else if (fd_find(&storage, fd) == 0)
	{
		storage->fd = fd;
		storage->size = buf->size;
		storage->next = NULL;
		ft_strlcpy(storage->str, buf->str, buf->size);
	}
	else
		storage_chaining(&storage, buf, fd);
}

void	fd_load(t_data *storage, t_buf *buf, int fd)
{
	*buf = (t_buf){{0, }, 0};
	if (fd_find(&storage, fd) == 0)
		return ;
	ft_strlcpy(buf->str, storage->str, storage->size);
	buf->size = storage->size;
}

int	fd_find(t_data **storage, t_buf *buf, int fd)
{
	t_data	*node;

	node = *storage;
	while (node != NULL && node->fd != fd)
		node = node->next;
	if (node == NULL)
		return (0);
	*storage = node;
	return (1);
}

int	eol_check(t_buf *buf)
{
	int		idx = 0;

	while (idx < buf->size && buf->str[idx] != '\n')
		++idx;
	if (idx < buf->size || buf->size != BUFFER_SIZE)
	{
		buf->size = idx;
		return (1);
	}
	return (0);
}
