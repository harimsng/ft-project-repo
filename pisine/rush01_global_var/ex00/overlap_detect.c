/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlap_detect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:16:05 by hseong            #+#    #+#             */
/*   Updated: 2021/10/17 21:09:21 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_lib.h"

extern int		*g_map;
extern int		*g_values;
extern int		g_len;
static int		*g_col;
static int		*g_row;

void			alloc_arr(void);
void			free_arr(void);
int				check(int idx, int jdx);

int	overlap_detect(void)
{
	int		idx;
	int		jdx;

	alloc_arr();
	idx = 0;
	while (idx < g_len)
	{
		jdx = 0;
		while (jdx < g_len)
		{
			if (!check(idx, jdx))
				return (0);
			++jdx;
		}
		++idx;
	}
	free_arr();
	return (1);
}

int	check(int idx, int jdx)
{
	int		num;

	if (g_map[idx * g_len + jdx] != 0)
	{
		num = 1 << (g_map[idx * g_len + jdx] - 1);
		if (g_row[idx] & num || g_col[jdx] & num)
		{
			free_arr();
			return (0);
		}
		g_row[idx] |= num;
		g_col[jdx] |= num;
	}
	return (1);
}	

void	alloc_arr(void)
{
	int		idx;

	g_col = (int *)malloc(sizeof(int) * g_len);
	g_row = (int *)malloc(sizeof(int) * g_len);
	if (g_col == NULL || g_row == NULL)
	{
		ft_putstr("Error\n");
		return ;
	}
	idx = 0;
	while (idx < g_len)
	{
		g_col[idx] = 0;
		g_row[idx] = 0;
		++idx;
	}
}

void	free_arr(void)
{
	free(g_row);
	free(g_col);
}
