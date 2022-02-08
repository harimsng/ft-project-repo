/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:26:33 by hseong            #+#    #+#             */
/*   Updated: 2021/12/02 01:26:58 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <unistd.h>

#include "ft_lib.h"

void		recur_solve(int boxes);
int			input_check(char *argv);
int			map_check(void);
int			overlap_detect(void);

const int	g_len = 4;
static int	g_ret = 0;
int			*g_values;
int			*g_map;

int	main(int argc, char **argv)
{
	int		idx;

	g_values = (int *)malloc(sizeof(int) * 4 * g_len);
	g_map = (int *)malloc(sizeof(int) * g_len * g_len);
	if (argc != 2 || !input_check(argv[1]) || g_values == NULL || g_map == NULL)
	{
		ft_putstr("Error\n");
		return (0);
	}
	idx = 0;
	while (idx < g_len * g_len)
		g_map[idx++] = 0;
	recur_solve(0);
	if (!g_ret)
		ft_putstr("No Solution\n");
	free(g_map);
	free(g_values);
	return (0);
}

int	input_check(char *argv)
{
	int			len;

	len = 0;
	while ((len < g_len * 4 * 2 - 1) && argv[len] != 0)
	{
		if (len % 2 == 0)
		{
			if (argv[len] < '1' || argv[len] > '0' + g_len)
				return (0);
			g_values[len / 2] = argv[len] - '0';
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
	int		idx;

	if (!overlap_detect() || !map_check())
	{
		g_map[boxes - 1] = 0;
		return ;
	}
	if (boxes == g_len * g_len)
	{
		print_result();
		++g_ret;
		return ;
	}
	idx = 0;
	while (idx < g_len)
	{
		g_map[boxes] = idx + 1;
		recur_solve(boxes + 1);
		++idx;
	}
	g_map[boxes - 1] = 0;
}
