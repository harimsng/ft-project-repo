/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 22:35:55 by hseong            #+#    #+#             */
/*   Updated: 2021/11/20 19:05:59 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		gnl_storage(char *buf, int fd, int io);
char	*gnl_strjoin(char const *s1, char const *s2);
char	*gnl_getnl(const char *s);
int		gnl_get_fd(t_buffer *fd_buf, int fd);

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	char		*buf_end;
	ssize_t		read_size;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	ft_memset(buf, 0, BUFFER_SIZE + 1);
	read_size = gnl_storage(buf, fd, 0);
	read_size += read(fd, buf + read_size, BUFFER_SIZE - read_size) - 1;
	line = ft_strdup("");
	while (line && read_size > -1)
	{
		buf_end = gnl_getnl(buf);
		if (buf_end != buf + BUFFER_SIZE && !gnl_storage(buf_end + 1, fd, 1))
			return (gnl_strjoin(line, buf));
		line = gnl_strjoin(line, buf);
		ft_memset(buf, 0, BUFFER_SIZE);
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	free(line);
	return (NULL);
}

int	gnl_storage(char *buf, int fd, int io)
{
	static t_buffer	fd_buf[3];
	int				idx;

	idx = gnl_get_fd(fd_buf, fd);
	if (!io)
	{
		if (idx <= 0)
			return (0);
		ft_strcpy(buf, fd_buf[idx - 1] + 4);
		ft_memset(fd_buf[idx - 1], 0, BUFFER_SIZE + 5);
		return (ft_strlen(buf));
	}
	if (idx >= 0)
		return (0);
	idx = -idx - 1;
	fd_buf[idx][0] = fd / 1000;
	fd_buf[idx][1] = (fd % 1000) / 100;
	fd_buf[idx][2] = (fd % 100) / 10;
	fd_buf[idx][3] = fd % 10;
	ft_strcpy(fd_buf[idx] + 4, buf);
	return (0);
}

int	gnl_get_fd(t_buffer *fd_buf, int fd)
{
	int		idx;
	int		fd_empty;

	idx = 0;
	fd_empty = 0;
	while (idx < 3)
	{
		if (fd_comp == 0)
			fd_empty = idx + 1;
		if (fd_comp == fd)
			return (idx + 1);
		++idx;
	}
	return (-fd_empty);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	char	*temp;
	size_t	idx;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (NULL);
	temp = ret;
	idx = 0;
	while (s1[idx])
		*temp++ = s1[idx++];
	idx = 0;
	while (s2[idx] && s2[idx] != '\n')
		*temp++ = s2[idx++];
	if (s2[idx] == '\n')
		*temp++ = '\n';
	*temp = 0;
	free((char *)s1);
	return (ret);
}

char	*gnl_getnl(const char *s)
{
	while (*s && *s != '\n')
		++s;
	if (!*s || *s == '\n')
		return ((char *)s);
	return (NULL);
}
