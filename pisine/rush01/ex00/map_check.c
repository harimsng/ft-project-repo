/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:16:14 by hseong            #+#    #+#             */
/*   Updated: 2021/10/16 19:16:15 by hseong           ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

#include <unistd.h>

int		col_up(void);
int		col_down(void);
int		row_left(void);
int		row_right(void);

extern const int	g_len;
extern int			*g_map;
extern int			*g_values;

int	map_check(void)
{
	if (col_up() && col_down() && row_left() && row_right())
		return (1);
	return (0);
}

int	col_up(void)
{
	int		max;
	int		idx;
	int		jdx;
	int		cnt;

	idx = 0;
	while (idx < g_len)
	{
		jdx = idx;
		max = g_map[jdx];
		cnt = 1;
		while (jdx < g_len * g_len)
		{
			if (g_map[jdx] == 0)
				return (1);
			cnt += max_change(&max, g_map[jdx]);
			jdx += g_len;
		}
		if (g_values[idx] != cnt)
			return (0);
		++idx;
	}
	return (1);
}

int	col_down(void)
{
	int		max;
	int		idx;
	int		jdx;
	int		cnt;

	idx = g_len;
	while (idx < 2 * g_len)
	{
		jdx = g_len * (g_len - 1) + idx - g_len;
		max = g_map[jdx];
		cnt = 1;
		while (jdx >= 0)
		{
			if (g_map[jdx] == 0)
				return (1);
			cnt += max_change(&max, g_map[jdx]);
			jdx -= g_len;
		}
		if (g_values[idx] != cnt)
			return (0);
		++idx;
	}
	return (1);
}

int	row_left(void)
{
	int		max;
	int		idx;
	int		jdx;
	int		cnt;

	idx = 2 * g_len;
	while (idx < 3 * g_len)
	{
		jdx = (idx - 2 * g_len) * g_len;
		max = g_map[jdx];
		cnt = 1;
		while (jdx < (1 + idx - 2 * g_len) * g_len)
		{
			if (g_map[jdx] == 0)
				return (1);
			cnt += max_change(&max, g_map[jdx]);
			++jdx;
		}
		if (g_values[idx] != cnt)
			return (0);
		++idx;
	}
	return (1);
}

int	row_right(void)
{
	int		max;
	int		idx;
	int		jdx;
	int		cnt;

	idx = 3 * g_len;
	while (idx < 4 * g_len)
	{
		jdx = (idx - 3 * g_len + 1) * g_len - 1;
		max = g_map[jdx];
		cnt = 1;
		while (jdx >= (idx - 3 * g_len) * g_len)
		{
			if (g_map[jdx] == 0)
				return (1);
			cnt += max_change(&max, g_map[jdx]);
			--jdx;
		}
		if (g_values[idx] != cnt)
			return (0);
		++idx;
	}
	return (1);
}
