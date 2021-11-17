/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejo <hyejo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 10:24:23 by hyejo             #+#    #+#             */
/*   Updated: 2021/10/24 21:54:02 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>

t_dicts	ft_get_dicts(char *file)
{
	t_dicts	result;
	t_dict	*dict_arr;
	int		dict_size;
	int		i;

	dict_size = ft_get_dict_size(file);
	dict_arr = malloc(sizeof(t_dict) * dict_size);
	result.size = dict_size;
	i = 0;
	while (dict_size--)
	{
		dict_arr[dict_size].num = get_dict_num(file, i);
		dict_arr[dict_size].name = get_dict_name(file, i);
		i++;
	}
	result.dicts = dict_arr;
	return (result);
}

int	ft_get_dict_size(char *file)
{
	int		fd;
	char	ch;
	int		size;

	fd = open(file, O_RDONLY);
	size = 0;
	while (read(fd, &ch, 1))
	{
		if (ch == '\n')
			size++;
	}
	close(fd);
	return (size);
}

long long	get_dict_num(char *file, int index)
{
	long long	result;
	int			fd;
	int			i;
	char		ch;

	fd = open(file, O_RDONLY);
	i = 0;
	ft_pass(fd, index);
	result = 0;
	while (read(fd, &ch, 1))
	{
		if ('0' <= ch && ch <= '9')
		{
			result *= 10;
			result += ch - '0';
		}
		else
			break ;
	}
	close(fd);
	return (result);
}

int	ft_get_name_len(char *file, int index)
{
	char	ch;
	int		fd;
	int		result;

	result = 0;
	fd = open(file, O_RDONLY);
	ft_pass(fd, index);
	ch = ft_pass_num(fd);
	while (ch != '\n')
	{
		result++;
		read(fd, &ch, 1);
	}
	close(fd);
	return (result);
}

char	*get_dict_name(char *file, int index)
{
	char	*result;
	int		fd;
	int		i;
	char	ch;
	int		name_len;

	fd = open(file, O_RDONLY);
	name_len = ft_get_name_len(file, index);
	result = malloc(sizeof(char) * (name_len + 1));
	ft_pass(fd, index);
	ch = ft_pass_num(fd);
	i = 0;
	while (i < name_len)
	{
		result[i] = ch;
		read(fd, &ch, 1);
		i++;
	}
	result[i] = 0;
	return (result);
}
