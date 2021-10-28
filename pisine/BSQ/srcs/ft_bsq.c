/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:43:42 by hseong            #+#    #+#             */
/*   Updated: 2021/10/28 12:33:17 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_mapprint(t_map *data);
int		double_free(void *addr1, void *addr2);

int	main(int argc, char **argv)
{
	t_map			*data;

	if (argc == 1)
	{
		data = ft_map(0);
		if (!data && ft_puterr("map error\n"))
			return (0);
		ft_solve(data, 0);
		ft_mapprint(data);
		double_free(data->map, data);
		return (0);
	}
	++argv;
	while (*argv)
	{
		data = ft_map(*argv++);
		if (!data && ft_puterr("map error\n"))
			continue ;
		ft_solve(data, 0);
		ft_mapprint(data);
		double_free(data->map, data);
	}
	return (0);
}

void	ft_mapprint(t_map *data)
{
	int			idx;
	int			jdx;

	idx = 0;
	while (idx < data->lines)
	{
		jdx = 0;
		while (jdx < data->width)
		{
			if (!data->map[data->width * idx + jdx])
				ft_putchar(data->obs);
			else if (idx > data->y - data->len && idx <= data->y
				&& jdx > data->x - data->len && jdx <= data->x)
				ft_putchar(data->full);
			else
				ft_putchar(data->empty);
			++jdx;
		}
		ft_putchar('\n');
		++idx;
	}
}

int	double_free(void *addr1, void *addr2)
{
	if (addr1)
		free(addr1);
	if (addr2)
		free(addr2);
	return (1);
}
