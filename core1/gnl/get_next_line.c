/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 22:35:55 by hseong            #+#    #+#             */
/*   Updated: 2021/11/28 02:10:55 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		gnl_load_buf(t_buf *fd_buf, t_buf **buf, int fd);
int		gnl_append(t_line *line, t_buf *buf);
int		gnl_read(t_buf *buf);

// maximum number of opened fd + stdin = 257
char	*get_next_line(int fd)
{
	static t_buf	fd_buf[257];
	t_buf			*buf;
	t_line			line;

	if (fd < 0 || BUFFER_SIZE < 1 || gnl_load_buf(fd_buf, &buf, fd))
		return (NULL);
	line = (t_line){128, 0, NULL};
	line.str = (unsigned char *)malloc(sizeof(char) * (line.cap));
	if (!line.str || !buf->str)
		return (NULL);
	while (gnl_append(&line, buf) && gnl_read(buf))
		continue ;
	if (buf->size == -1 || line.size == 0)
	{
		free(line.str);
		free(buf->str);
		buf->fd = 0;
		buf->str = NULL;
		return (NULL);
	}
	return ((char *)line.str);
}
//	buf->size == -1
//		read() error
//	line.size == 0
//		only EOF has been read(nothing left in the fd)

int	gnl_read(t_buf *buf)
{
	buf->size = read(buf->fd * (buf->fd != INT_MAX), buf->str, BUFFER_SIZE);
	if (buf->size < 0)
		return (0);
	else if (!buf->size)
	{
		free(buf->str);
		buf->fd = 0;
		buf->str = NULL;
		return (0);
	}
	buf->str[buf->size] = 0;
	return (1);
}

//		check whether preserved fd buffer exists or not.
// 		if it exists, set t_buf pointer to point to the fd buffer.
//
//		if fd buffer is not found,
//		find empty buffer which has buf->fd = -1 and set the pointer.
//		if there's no empty buffer, return error.
int	gnl_load_buf(t_buf *fd_buf, t_buf **buf, int fd)
{
	int				idx;

	idx = 0;
	fd += INT_MAX * (!fd);
	while (idx < 257 && fd_buf[idx].fd != fd)
		++idx;
	if (idx < 257)
		return (!(*buf = fd_buf + idx)->str);
	while (idx > 0 && fd_buf[idx - 1].str)
		--idx;
	if (idx == 0)
		return (1);
	*buf = fd_buf + idx - 1;
	(*buf)->str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	(*buf)->size = 0;
	(*buf)->str[(*buf)->size] = 0;
	(*buf)->fd = fd;
	return (0);
}

//		if expected line size is bigger than capacity,
//		allocate new array with proper capacity and memcpy original contents.
//		memcpy contents of buffer into line->str and add null at the end.
int	gnl_append(t_line *line, t_buf *buf)
{
	unsigned char	*ptr;
	int				idx;

	if (line->size + buf->size >= line->cap)
	{
		line->cap *= 2 * (line->size + buf->size) / line->cap;
		ptr = malloc(sizeof(char) * (line->cap));
		if (!ptr)
			return (line->size = 0);
		ft_memcpy(ptr, line->str, line->size + 1);
		free(line->str);
		line->str = ptr;
	}
	idx = 0;
	while (idx < buf->size && buf->str[idx++] != '\n')
		continue ;
	ft_memcpy(line->str + line->size, buf->str, idx);
	ft_memcpy(buf->str, buf->str + idx, buf->size - idx);
	line->size += idx;
	line->str[line->size] = 0;
	buf->size -= idx;
	buf->str[buf->size] = 0;
	return (!line->size || line->str[line->size - 1] != '\n');
}
