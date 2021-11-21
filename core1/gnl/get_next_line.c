/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 22:35:55 by hseong            #+#    #+#             */
/*   Updated: 2021/11/22 03:10:54 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		gnl_storage(char *buf, int fd, int io);
char	*gnl_strjoin(char const *s1, char const *s2);
char	*gnl_getnl(const char *s);
int		gnl_get_fd(t_buf *fd_buf, int fd);
void	gnl_process(t_line line, t_buf fd_buf, int fd, ssize_t *read_size);

char	*get_next_line(int fd)
{
	static t_buf	fd_buf[3] = {{-1, 0, {0,}}, {-1, 0, {0,}}, {-1, 0, {0,}}};
	t_line			line;
	ssize_t			read_size;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = (t_line){0, (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))};
	if (!line.str)
		return (NULL);
	ft_memset(line.str, 0, BUFFER_SIZE + 1);
	ft_strcpy(line.str, fd_buf[idx].buf);
	while (line.str && read_size > -1)
		gnl_process(line, fd_buf[idx], fd, &read_size);
	if (read_size < 0)
		free(line.str);
	return (line.str);
}

void	gnl_process(t_line line, t_buf fd_buf, int fd, ssize_t *read_size);
{

}




	while (line && read_size > -1)
	{
		buf_end = gnl_getnl(buf);
		if (buf_end != buf + BUFFER_SIZE && !gnl_storage(buf, fd, buf_end - buf + 1))
			return (gnl_strjoin(line, buf));
		line = gnl_strjoin(line, buf);
		ft_memset(buf, 0, BUFFER_SIZE + 1);
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	free(line);
	return (NULL);
}

// !!io, io : INPUT to buffer
// !io		: OUTPUT from buffer
int	gnl_storage(char *buf, int fd, int io)
{
	static t_buf	fd_buf[3]
		= {{-1, 0, {0, }}, {-1, 0, {0, }}, {-1, 0, {0, }}};
	int				idx;

	idx = gnl_get_fd(fd_buf, fd);
	if ((!io && idx <= 0) || (!!io && idx >= 0))
		return (0);
	idx = idx * (1 - 2 * !!io) - 1;
	if (fd_buf[idx].eof)
	{
		fd_buf[idx].eof = 0;
		fd_buf[idx].fd = -1;
		return (-1);
	}
	fd_buf[idx].fd = -!io + fd * !!io;
	(void)(!io && ft_strcpy(buf, fd_buf[idx].buf)
		&& ft_memset(fd_buf[idx].buf, 0, BUFFER_SIZE + 1));
	(void)(!!io && ft_strcpy(fd_buf[idx].buf, buf + io));
	fd_buf[idx].eof = !!io * !buf[io - !!io];
	return (!io * ft_strlen(buf));
}

int	gnl_get_fd(t_buf *fd_buf, int fd)
{
	int		idx;
	int		fd_empty;

	idx = 0;
	fd_empty = 0;
	while (idx < 3)
	{
		if (fd_buf[idx].fd == fd)
			return (idx + 1);
		if (fd_buf[idx].fd == -1)
			fd_empty = idx + 1;
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
