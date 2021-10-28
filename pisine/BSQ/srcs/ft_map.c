/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:43:44 by hseong            #+#    #+#             */
/*   Updated: 2021/10/28 12:33:32 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	read_map(int fd, t_map *data, int num_line, int idx);
int	get_mapdata(int fd, t_map *data);
int	get_width(int fd, t_map *data, t_uc buf, int read_size);
int	data_check(t_uc *str);

// even number of printable character?
t_map	*ft_map(char *filename)
{
	t_map			*data;
	int				fd;

	data = (t_map *)malloc(sizeof(t_map));
	if (!data)
		return (0);
	*data = (t_map){0, 0, 0, 0, 0, 0, 0, 0, 0};
	fd = 0;
	if (filename)
		fd = open(filename, O_RDONLY);
	if (fd < 0 || get_mapdata(fd, data) || read_map(fd, data, 0, 0))
	{
		ft_free(data->map);
		ft_free(data);
		if (fd > 0)
			close(fd);
		return (0);
	}
	if (fd != 0)
		close(fd);
	return (data);
}

int	get_mapdata(int fd, t_map *data)
{
	t_uc		buf[4];
	int			read_size;

	read_size = read(fd, buf, 1);
	while (read_size > 0 && *buf >= '0' && *buf <= '9')
	{
		data->lines = data->lines * 10 + (int)*buf - '0';
		read_size = read(fd, buf, 1);
	}
	if (read_size < 0 || data->lines == 0)
		return (1);
	read_size = read(fd, buf + 1, 3);
	if (read_size < 0 || data_check(buf))
		return (1);
	data->empty = buf[0];
	data->obs = buf[1];
	data->full = buf[2];
	return (get_width(fd, data, 0, 0));
}

int	data_check(t_uc *str)
{
	if (str[3] != '\n')
		return (1);
	else if (str[0] == str[1] || str[1] == str[2] || str[3] == str[1])
		return (1);
	else if (str[0] < 32 || str[0] == 127 || str[1] < 32 || str[1] == 127
		|| str[2] < 32 || str[2] == 127)
		return (1);
	return (0);
}

int	read_map(int fd, t_map *data, int num_line, int idx)
{
	t_uc			*buf;
	int				read_size;

	buf = (t_uc *)malloc(sizeof(t_uc) * data->width + 1);
	read_size = data->width + 1;
	while (read_size == data->width + 1 && ++num_line < data->lines)
	{
		idx = -1;
		read_size = read(fd, buf, data->width + 1);
		if ((read_size < 0 && ft_free(buf))
			|| (ft_strcheck(buf, data->width) && ft_free(buf)))
			break ;
		while (++idx < data->width)
		{
			data->map[num_line * data->width + idx] = 1;
			if (buf[idx] == data->obs)
				data->map[num_line * data->width + idx] = 0;
			else if (buf[idx] != data->empty && ft_free(buf))
				return (1);
		}
	}
	if ((num_line != data->lines && ft_free(buf))
		|| (read(fd, buf, 1) > 0 && ft_free(buf)) || !ft_free(buf))
		return (1);
	return (0);
}

// buffer is a character
int	get_width(int fd, t_map *data, t_uc buf, int read_size)
{
	t_uc				*first_line;

	first_line = malloc(sizeof(t_uc) * 1000);
	read_size = read(fd, &buf, 1);
	while (read_size > 0 && buf != '\n')
	{
		first_line[data->width] = 1;
		if (buf == data->obs)
			first_line[data->width] = 0;
		else if (buf != data->empty)
		{
			read(fd, first_line, 1000);
			free(first_line);
			return (1);
		}
		++data->width;
		read_size = read(fd, &buf, 1);
	}
	data->map = malloc(sizeof(t_uc) * data->width * data->lines);
	if ((data->width == 0 || read_size < 0
			|| !data->map) && ft_free(first_line))
		return (1);
	ft_strccpy(data->map, first_line, data->width);
	free(first_line);
	return (0);
}
