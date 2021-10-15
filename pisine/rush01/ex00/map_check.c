#include "ft_lib.h"

int		col_up(int boxes);
int		col_down(int boxes);
int		row_left(int boxes);
int		row_right(int boxes);
int		overlap_check(void);

extern const int	g_len;
extern int			*g_map;
extern int			*g_values;

int	map_check(int boxes)
{
	int		ret;

	ret = col_up(boxes) + col_down(boxes);
	ret += row_left(boxes) + row_right(boxes);
	if (ret != 4)
		return (0);
	return (1);
}

int	col_up(int boxes)
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
			if (jdx >= boxes)
				return (1);
			jdx += g_len;
			cnt += max_change(&max, g_map[jdx]);
		}
		if (g_values[idx] != cnt)
			return (0);
		++idx;
	}
	return (1);
}

int	col_down(int boxes)
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
			if (jdx >= boxes)
				return (1);
			jdx -= g_len;
			cnt += max_change(&max, g_map[jdx]);
		}
		if (g_values[idx] != cnt)
			return (0);
		++idx;
	}
	return (1);
}

int	row_left(int boxes)
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
			if (jdx >= boxes)
				return (1);
			++jdx;
			cnt += max_change(&max, g_map[jdx]);
		}
		if (g_values[idx] != cnt)
			return (0);
		++idx;
	}
	return (1);
}

int	row_right(int boxes)
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
			if (jdx >= boxes)
				return (1);
			--jdx;
			cnt += max_change(&max, g_map[jdx]);
		}
		if (g_values[idx] != cnt)
			return (0);
		++idx;
	}
	return (1);
}

void	overlap_check(void)
{
	int		
