#include <stdlib.h>

#include "ft_lib.h"

int		col_check(int value, int *g_map, int g_len, int idx);
int		row_check(int value, int *g_map, int g_len, int idx);

int	map_check_2(int *g_values, int *g_map, int g_len)
{
	int		idx;

	idx = 0;
	while (idx < g_len)
	{
		if (!row_check(g_values[idx], g_map, g_len, idx))
			return (0);
		if (!col_check(g_values[idx + 2 * g_len], g_map, g_len, idx))
			return (0);
		++idx;
	}
	return (1);
}

int	col_check(int g_value, int *g_map, int g_len, int idx)
{
	int		jdx;
	int		max;

	if (idx > g_len)
		idx = 2 * g_len + idx;
	max = g_map[idx];
	jdx = 0;
	while (jdx < g_len)
	{
		idx -= g_len;
		if (g_map[idx] == 0)
			return (1);
		if (max < g_map[idx])
			max_change(&max, g_map[idx]);
	}
	if (g_value != 0)
		return (0);
	return (1);
}
