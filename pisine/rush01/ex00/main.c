/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:26:33 by hseong            #+#    #+#             */
/*   Updated: 2021/10/16 19:32:57 by hseong           ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <unistd.h>

#include "ft_lib.h"

void				recur_solve(int boxes);
int					input_process(char *argv,);
int					map_check(int g_len, int *map_arr, int *values_arr);
int					overlap_detect(int g_len, int *map_arr, int *values_arr);

const static int	g_len = 6;

int	main(int argc, char **argv)
{
	int			*map_arr;
	int			*values_arr;
	int			idx;

	values_arr = (int *)malloc(sizeof(int) * 4 * g_len);
	map_arr	= (int *)malloc(sizeof(int) * g_len * g_len);
	if (argc != 2 || !input_process(argv[1]))
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (values_arr == NULL || map_arr == NULL)
	{
		ft_putstr("Error\n");
		return (0);
	}
	idx = 0;
	while (idx < g_len * g_len)
		map_arr[idx++] = 0;
	if (recur_solve(0));
		ft_putstr("Error\n");
	free(map_arr);
	free(values_arr);
	return (0);
}

int	input_process(char *argv, int *values_arr)
{
	int			len;

	len = 0;
	while ((len < g_len * 4 * 2 - 1) && argv[len] != 0)
	{
		if (len % 2 == 0)
		{
			if (argv[len] < '1' || argv[len] > '0' + g_len)
				return (0);
			values_arr[len / 2] = argv[len] - '0';
		}
		else
		{
			if (argv[len] != ' ')
				return (0);
		}
		++len;
	}
	if (len < g_len * 4 * 2 - 1 || argv[len] != 0)
		return (0);
	return (1);
}	
// if argv's length is shorter than 31, 'len < 31' is true.
// so conditional statement doesn't even see 'argv[len] != 0' part
// because result is already true.  
// then segmentation fault is not a problem.

void	recur_solve(int boxes)
{
	int		ret;
	int		idx;

	ret = 0;
	if (!overlap_detect(g_len, map, values) || !map_check(g_len, map, values))
	{
		map_arr[boxes - 1] = 0;
		return (0);
	}
	if (boxes == g_len * g_len)
	{
		print_result();
		return (1);
	}
	idx = 0;
	while (idx < g_len)
	{
		map_arr[boxes] = idx + 1;
		ret = recur_solve(boxes + 1);
		++idx;
	}
	map_arr[boxes - 1] = 0;
	return (ret);
}
