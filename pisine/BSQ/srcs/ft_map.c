/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:43:44 by hseong            #+#    #+#             */
/*   Updated: 2021/10/27 22:16:10 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	read_map(int fd, t_map *data, unsigned int num_line);
int	get_mapdata(int fd, t_map *data);
int	get_width(int fd, t_map *data);
int	data_check(char *str);

// even number of printable character?
t_map	*ft_map(char *filename)
{
	int				fd;
	unsigned int	idx;
	t_map		*data;

	data = (t_map *)malloc(sizeof(t_map));
	*data = (t_map){0, 0, 0, 0, 0, 0};
	data->pos = malloc(sizeof(unsigned long long) * data->lines);
	idx = 0;
	while (idx < data->lines)
	{
		data->pos[idx][0] = 0;
		data->pos[idx++][1] = 0;
	}	
	fd = 0;
	if (filename)
		fd = open(filename, O_RDONLY);
	ft_putstr("ft_map1\n");
	if (!data->pos || get_mapdata(fd, data) || read_map(fd, data, 1))
	{
		ft_putstr("ft_map error\n");
		if (fd != 0)
			if (close(fd) < 0)
		return (0);
	}
	if (fd != 0)
		close(fd);
	return (data);
}

int	get_mapdata(int fd, t_map *data)
{
	char		buf[4];
	int			read_size;
	
	read_size = read(fd, buf, 1);
	while (read_size > 0 && *buf >= '0' && *buf <= '9')
	{
		data->lines = data->lines * 10 + (unsigned int)*buf - '0';
		read_size = read(fd, buf, 1);
	}
	if (read_size < 0 || data->lines == 0)
		return (1);
	read_size = read(fd, buf + 1, 3);
	if (read_size < 0 || data_check(buf) || get_width(fd, data))
		return (1);
	data->empty = buf[0];
	data->obs = buf[1];
	data->full = buf[2];
	ft_putstr("get_mapdata end\n");
	return (0);	
}

int	data_check(char *str)
{
	if (str[3] != '\n')
		return (1);
	else if (str[0] == str[1] || str[1] == str[2] || str[3] == str[1])
		return (1);
	else if (str[0] < 32 || str[0] == 127 || str[1] < 32 || str[1] == 127
		|| str[2] < 32 || str[2] == 127)
		return (1);
	return(0);
}

int	read_map(int fd, t_map *data, unsigned int num_line)
{
	char			*buf;
	int				read_size;
	unsigned int	idx;
	
	buf = (char *)malloc(sizeof(char) * data->width + 1);
	while (num_line < data->lines)
	{
		idx = 0;
		read_size = read(fd, buf, data->width + 1);
		if ((read_size < 0 && ft_free(buf)) || 
			(ft_strcheck(buf, data->width) && ft_free(buf)))
			return (1);
		while (idx < data->width)
		{
			ft_putstr("read_loop1\n");
			if (buf[idx++] == data->obs)
			{
				ft_putstr("obstacle\n");
				data->pos[num_line][idx >> 6]
					|= 1 << (idx & 63);
			}
		}
	}
	free(buf);
	ft_putstr("read_map end\n");
	return (0);
}

int	get_width(int fd, t_map *data)
{
	char				buf[MAX_WIDTH];
	int					read_size;
	unsigned int		idx;

	idx = 0;
	read_size = read(fd, buf, MAX_WIDTH);
	while (read_size > 0 && buf[idx] && buf[idx] != '\n')
	{
		if (buf[idx] == data->obs)
		{
			(data->pos)[0][idx >> 6] |= 1 << (idx & 63);
		}
		++idx;
		ft_putnbr(idx);
	}
	data->width = idx;
	if (data->width == 0 || read_size < 0)
		return (1);
	ft_putstr("get_width end\n");
	return (0);
}
