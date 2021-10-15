/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:26:33 by hseong            #+#    #+#             */
/*   Updated: 2021/10/15 23:35:35 by hseong           ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <unistd.h>

#include "ft_lib.h"

void		get_it_done(int boxes);
void		print_result(void);
int			input_check(char *argv);
int			map_check(int boxes);

const int	g_len = 4;
static int	g_ret = 0;
int			*g_values;
int			*g_map;


int	main(int argc, char **argv)
{
	int		idx;

	g_values = (int *)malloc(sizeof(int) * g_len * g_len);
	g_map = (int *)malloc(sizeof(int) * g_len * g_len);
	if (argc != 2 || input_check(argv[1]))
	{
		ft_putstr("Error\n");
		return (0);
	}
	while (idx < g_len * g_len)
		g_map[idx++] = 0;
	ft_putstr("processing\n"); // remove this line
	get_it_done(0);
	if (!g_ret)
		ft_putstr("Error\n");
	free(g_map);
	free(g_values);
	return (0);
}

int	input_check(char *argv)
{
	int			len;

	len = 0;
	while ((len < g_len * g_len * 2 - 1) && argv[len] != 0)
	{
		if (len % 2 == 0)
		{
			if (argv[len] < '1' || argv[len] > '0' + g_len)
				return (1);
			g_values[len / 2] = argv[len] - '0';
		}
		else
		{
			if (argv[len] != ' ')
				return (1);
		}
		++len;
	}
	if (len < g_len * g_len * 2 - 1 || argv[len] != 0)
		return (1);
	return (0);
}	
// if argv's length is shorter than 31, 'len < 31' is true.
// so conditional statement doesn't even see 'argv[len] != 0' part
// because result is already true.  
// then segmentation fault is not a problem.

void	get_it_done(int boxes)
{
	int		idx;

	print_result();
	if (!map_check(boxes))
		return ;
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
		get_it_done(boxes + 1);
		++idx;
	}
}

void	print_result(void)
{
	int			idx;
	char		num;

	idx = 0;
	while (idx < g_len * g_len)
	{
		num = g_map[idx] + '0';
		write(1, &num, 1);
		if (idx % g_len == g_len - 1)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		++idx;
	}
}
