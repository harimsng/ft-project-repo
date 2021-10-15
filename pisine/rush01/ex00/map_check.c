#include "ft_lib.h"

int		col_up(void);
int		col_down(void);
int		row_left(void);
int		row_right(void);

extern const int	g_len;
extern int			*g_map;
extern int			*g_values;

int	map_check(void)
{
	int		ret;

	ret = col_up() + col_down();
	ret += row_left() + row_right();
	if (ret != 4)
	{
		ft_putstr("map_check\n");
		return (0);
	}
	return (1);
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
			{
				ft_putstr("col up\n");
				return (1);
			}
			jdx += g_len;
			cnt += max_change(&max, g_map[jdx]);
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
			{
				ft_putstr("col down\n");
				return (1);
			}
			jdx -= g_len;
			cnt += max_change(&max, g_map[jdx]);
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
			{
				ft_putstr("row left\n");
				return (1);
			}
			++jdx;
			cnt += max_change(&max, g_map[jdx]);
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
			{
				ft_putstr("row right\n");
				return (1);
			}
			--jdx;
			cnt += max_change(&max, g_map[jdx]);
		}
		if (g_values[idx] != cnt)
			return (0);
		++idx;
	}
	return (1);
}
