/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 22:35:55 by hseong            #+#    #+#             */
/*   Updated: 2021/11/23 13:52:51 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		gnl_load_buf(t_buf *fd_buf, t_buf **buf, int fd);
int		gnl_process(t_line *line, t_buf *buf);

char	*get_next_line(int fd)
{
	static t_buf	fd_buf[3] = {{-1, 0, {0,}}, {-1, 0, {0,}}, {-1, 0, {0,}}};
	t_buf			*buf;
	t_line			line;

	if (fd < 0 || BUFFER_SIZE < 1 || gnl_load_buf(fd_buf, &buf, fd))
		return (NULL);
	line = (t_line){128, buf->size, NULL};
	while (line.cap <= buf->size)
		line.cap *= 2;
	line.str = (unsigned char *)malloc(sizeof(char) * (line.cap));
	while (line.str && !gnl_process(&line, buf))
		continue ;
	// need error flag 
	if (buf->size < 0)
		free(line.str);
	return (line.str);
}

int	gnl_process(t_line *line, t_buf *buf);
{
	buf->size = read(buf->fd, buf->str, BUFFER_SIZE);
	if (!gnl_strjoin(line, buf) || buf->size != BUFFER_SIZE)
		return (1);
}

int	gnl_load_buf(t_buf *fd_buf, t_buf **buf, int fd)
{
	int				idx;

	idx = 0;
	while (idx < 3 && fd_buf[idx].fd != fd)
		++idx;
	if (idx < 3)
	{
		*buf = fd_buf[idx];
		(*buf).size = ((*buf).size != -1) * ((*buf).size;
		(*buf).fd = ((*buf).size != -1) * ((*buf).fd;
		return (fd_buf[idx].size == -1);
	}
	while (idx > 0 && fd_buf[idx - 1].fd != -1)
		--idx;
	*buf = fd_buf[idx - 1];
	(*buf).fd = fd;
	return (idx == 0);
}

void	*gnl_strjoin(t_line *line, t_buf *buf)
{
	unsigned char	*ptr;

	if (line->size + buf->size >= line->cap)
	{
		while (line->size + buf->size >= line->cap)
			line->cap *= 2;
		ptr = (unsigned char *)malloc(sizeof(char) * (line->cap));
		if (!ptr)
			return (NULL);
		ft_memcpy(ptr, line->str, line->size + 1);
		free(line->str);
		line->str = ptr;
	}
	ft_memcpy(line->str + line->size, buf->str, buf->size);
	line->size += buf->size;
	line->str[line->size] = 0;
	return ((void *)line->str);
}
