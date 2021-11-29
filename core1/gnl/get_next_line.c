/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 22:35:55 by hseong            #+#    #+#             */
/*   Updated: 2021/11/29 20:04:18 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		gnl_load_buf(t_buf *fd_buf, t_buf *buf, int fd);
int		gnl_save_buf(t_buf *fd_buf, t_buf *buf);
int		gnl_append(t_line *line, t_buf *buf);
void	gnl_reset_buf(t_buf *buf);

// maximum number of opened fd + stdin = 257
char	*get_next_line(int fd)
{
	static t_buf	fd_buf[257];
	t_buf			buf;
	t_line			line;

	if (fd < 0 || BUFFER_SIZE < 1 || gnl_load_buf(fd_buf, &buf, fd))
		return (NULL);
	line = (t_line){128, 0, ft_calloc(128, sizeof(char))};
	if (!line.str)
		return (NULL);
	while (gnl_append(&line, &buf))
	{
		buf.size = read(buf.fd * (buf.fd != INT_MAX), buf.str, BUFFER_SIZE);
		if (buf.size < 1)
			break ;
	}
	if (line.size < 1 || buf.size < 0
		|| (buf.size > 0 && gnl_save_buf(fd_buf, &buf)))
	{
		free(line.str);
		line.str = NULL;
	}
	gnl_reset_buf(&buf);
	return ((char *)line.str);
}
//	buf->size == -1
//		read() error
//	line.size == 0
//		only EOF has been read(nothing left in the fd)

//		check whether preserved fd_buf exists or not.
// 		if it exists, move its contents to buf.
int	gnl_load_buf(t_buf *fd_buf, t_buf *buf, int fd)
{
	int				idx;

	fd += INT_MAX * (!fd);
	*buf = (t_buf){fd, 0, ft_calloc(BUFFER_SIZE, sizeof(char))};
	if (!(buf->str))
		return (1);
	idx = 0;
	while (idx < 257 && fd_buf[idx].fd != fd)
		++idx;
	if (idx == 257)
		return (0);
	ft_memcpy(buf->str, fd_buf[idx].str, fd_buf[idx].size);
	buf->size = fd_buf[idx].size;
	gnl_reset_buf(fd_buf + idx);
	return (0);
}

int	gnl_save_buf(t_buf *fd_buf, t_buf *buf)
{
	int		idx;

	idx = 0;
	while (idx < 257 && fd_buf[idx].fd != 0)
		++idx;
	if (idx == 257)
		return (1);
	fd_buf[idx].fd = buf->fd;
	fd_buf[idx].size = buf->size;
	fd_buf[idx].str = ft_calloc(buf->size, sizeof(char));
	ft_memcpy(fd_buf[idx].str, buf->str, buf->size);	
	return (0);
}

//		if expected line size is bigger than capacity,
//		allocate new array with proper capacity and memcpy original contents.
int	gnl_append(t_line *line, t_buf *buf)
{
	unsigned char	*ptr;
	int				idx;

	if (line->size + buf->size >= line->cap)
	{
		line->cap = line->size + buf->size + 1;
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
	return (!line->size || line->str[line->size - 1] != '\n');
}

void gnl_reset_buf(t_buf *buf)
{
	free(buf->str);
	buf->str = NULL;
	buf->fd = 0;
	buf->size = 0;
}
