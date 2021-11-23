/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 22:35:55 by hseong            #+#    #+#             */
/*   Updated: 2021/11/23 21:51:04 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		gnl_load_buf(t_buf *fd_buf, t_buf **buf, int fd);
int		gnl_process(t_line *line, t_buf *buf);
int		gnl_strjoin(t_line *line, t_buf *buf);

char	*get_next_line(int fd)
{
	static t_buf	fd_buf[3] = {{-1, 0, {0,}}, {-1, 0, {0,}}, {-1, 0, {0,}}};
	t_buf			*buf;
	t_line			line;

	if (fd < 0 || BUFFER_SIZE < 1 || gnl_load_buf(fd_buf, &buf, fd))
		return (NULL);
	line = (t_line){128, 0, NULL};
	line.str = (unsigned char *)malloc(sizeof(char) * (line.cap));
	while (line.str && !gnl_process(&line, buf))
		continue ;
	if (buf->size == -1 || line.size == 0)
	{
		buf->fd = -1;
		buf->size = 0;
		free(line.str);
		return (NULL);
	}
	return ((char *)line.str);
}

// if read_size != buf->size, there's newline in the buffer.
// if buf->size != BUFFER_SIZE, EOF have been read.
int	gnl_process(t_line *line, t_buf *buf)
{
	int				read_size;

	buf->size += read(buf->fd, buf->str + buf->size, BUFFER_SIZE - buf->size);
	if (buf->size < 0)
		return (1);
	read_size = gnl_strjoin(line, buf);
	if (read_size != buf->size)
	{
		read_size += buf->str[read_size] == '\n';
		buf->size -= read_size;
		ft_memcpy(buf->str, buf->str + read_size, buf->size);
		return (1);
	}
	else if (buf->size != BUFFER_SIZE)
	{
		buf->size = -2 * (buf->fd == 0);
		buf->fd = -(buf->fd != 0);
		return (1);
	}
	buf->size = 0;
	return (0);
}

int	gnl_load_buf(t_buf *fd_buf, t_buf **buf, int fd)
{
	int				idx;
	int				eof_flag;

	idx = 0;
	while (idx < 3 && fd_buf[idx].fd != fd)
		++idx;
	if (idx < 3)
	{
		*buf = fd_buf + idx;
		eof_flag = (*buf)->size == -2;
		(*buf)->fd = !eof_flag * (*buf)->fd - eof_flag;
		(*buf)->size = !eof_flag * (*buf)->size;
		return (eof_flag);
	}
	while (idx > 0 && fd_buf[idx - 1].fd != -1)
		--idx;
	if (idx == 0)
		return (1);
	*buf = fd_buf + idx - 1;
	(*buf)->fd = fd;
	return (0);
}

int	gnl_strjoin(t_line *line, t_buf *buf)
{
	unsigned char	*ptr;
	int				idx;
	int				nl_flag;

	if (line->size + buf->size >= line->cap)
	{
		line->cap *= 2 * (line->size + buf->size) / line->cap;
		ptr = (unsigned char *)malloc(sizeof(char) * (line->cap));
		if (!ptr)
			return (0);
		ft_memcpy(ptr, line->str, line->size + 1);
		free(line->str);
		line->str = ptr;
	}
	idx = 0;
	while (idx < buf->size && buf->str[idx] != '\n')
		++idx;
	nl_flag = (buf->str[idx] == '\n' && idx < buf->size);
	ft_memcpy(line->str + line->size, buf->str, idx + nl_flag);
	line->size += idx + nl_flag;
	line->str[line->size] = 0;
	return (idx); 
}
