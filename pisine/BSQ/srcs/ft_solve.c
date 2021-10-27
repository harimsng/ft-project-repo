#include "../includes/ft.h"

t_uc	three_min(t_uc a, t_uc b, t_uc c);
void	edge_solve(t_map *data);

void	ft_solve(t_map *data, int pos)
{
	int			idx;
	int			jdx;

	edge_solve(data);
	idx = 1;
	while (idx < data->lines)
	{
		jdx = 1;
		while (jdx < data->width)
		{
			pos = idx * data->width + jdx;
			if (data->map[pos])
			{
				data->map[pos] += three_min(data->map[pos - data->width],
					   data->map[pos - data->width - 1], data->map[pos - 1]);
				if ((t_uc)data->map[pos] > (t_uc)data->len)
				{
					data->len = data->map[pos];
					data->x = jdx;
					data->y = idx;
				}
			}
			ft_putnbr(data->map[pos]);
			++jdx;
		}
		++idx;
		ft_putchar('\n');
	}
}

void	edge_solve(t_map *data)
{
	int		idx;
	int		jdx;

	jdx = -1;
	while (++jdx < data->width)
	{
		if (data->map[jdx])
		{
			data->len = 1;
			data->x = jdx;
			data->y = 0;
			return ;
		}
	}
	idx = -1;
	while (++idx < data->lines)
	{
		if (data->map[data->width * idx++])
		{
			data->len = 1;
			data->x = 0;
			data->y = idx;
			return ;
		}
	}
}

t_uc	three_min(t_uc a, t_uc b, t_uc c)
{
	return (a * (a <= c && a < b) + b * (b < c && b <= a)
			+ c * (c < a && c <= b) + a * (a == b && b == c));
}
