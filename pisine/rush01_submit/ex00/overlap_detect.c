/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlap_detect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:16:05 by hseong            #+#    #+#             */
/*   Updated: 2021/10/16 19:16:07 by hseong           ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_lib.h"

extern int		*g_map;
extern int		*g_values;
extern int		g_len;
static int		*col;
static int		*row;

void			alloc_arr(void);
void			free_arr(void);

int	overlap_detect(void)
{
	int		idx;
	int		jdx;
	int		num;
	
	alloc_arr();
	idx = 0;
	while (idx < g_len)
	{
		jdx = 0;
		while (jdx < g_len)
		{
			if (g_map[idx * g_len + jdx] != 0)
			{
				num = 1 << (g_map[idx * g_len + jdx] - 1);
				if (row[idx] & num || col[jdx] & num)
				{
					free_arr();
					return (0);
				}
				row[idx] |= num;
				col[jdx] |= num;
			}
			++jdx;
		}
		++idx;
	}
	free_arr();
	return (1);
}

void	alloc_arr(void)
{
	int		idx;

	col = (int *)malloc(sizeof(int) * g_len);
	row = (int *)malloc(sizeof(int) * g_len);
	if (col == NULL || row == NULL)
	{
		ft_putstr("Error\n");
		return ;
	}
	idx = 0;
	while (idx < g_len)
	{
		col[idx] = 0;
		row[idx] = 0;
		++idx;
	}
}

void	free_arr(void)
{
	free(row);
	free(col);
}
