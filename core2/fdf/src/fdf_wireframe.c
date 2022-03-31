/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_wireframe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:31:10 by hseong            #+#    #+#             */
/*   Updated: 2022/03/31 21:33:26 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_render_order.h"
# include <stdio.h>
# include "mlx.h"

static const t_render	g_render_d[8] = {
	render_d0,
	render_d1,
	render_d2,
	render_d3,
	render_d4,
	render_d5,
	render_d6,
	render_d7
};

static const t_render	g_render_n[8] = {
	render_n0,
	render_n1,
	render_n2,
	render_n3,
	render_n4,
	render_n5,
	render_n6,
	render_n7
};

static int	get_octant(t_map_info *map_info);

void	fdf_wireframe(t_img_elem *img_elem, t_map_info *map_info)
{
	t_draw		draw;
	int			octant;

	draw = fdf_drawline;
	octant = get_octant(map_info);
	if (map_info->hor_scale > 24)
		draw = fdf_aa_drawline;
	if (map_info->colored == TRUE)
		g_render_d[octant](img_elem, map_info, draw);
	else
		g_render_n[octant](img_elem, map_info, draw);
}

int	get_octant(t_map_info *map_info)
{
	return (4 * (sin(map_info->hor_angle * 4) > 0)
		+ (3 * (cos(map_info->ver_angle) < 0)
		^ ((sin(map_info->hor_angle) < 0)
			+ 2 * (cos(map_info->hor_angle) < 0))));
}

//function to find octant more accurately. not working now.
/*
static const int		g_index_table[8] = {
	0, 2, 3, 1,
	3, 1, 0, 2
};

int	get_octant(t_map_info *map_info)
{
	static char	buf[100];
	int			idx;
	int			minidx;
	double		minval;
	double		edges[4];

	edges[0] = map_info->map_proj[0][0].y;
	edges[1] = map_info->map_proj[0][map_info->col - 1].y;
	edges[2] = map_info->map_proj[map_info->row - 1][map_info->col - 1].y;
	edges[3] = map_info->map_proj[map_info->row - 1][0].y;
	minval = 2147483647;
	if (edges[1] < minval)
	{
		minidx = 1;
		minval = edges[1];
	}
	if (edges[2] < minval)
	{
		minidx = 2;
		minval = edges[2];
	}
	if (edges[3] < minval)
	{
		minidx = 3;
		minval = edges[3];
	}
	if (edges[0] < minval)
	{
		minidx = 4;
		minval = edges[0];
	}
	idx = g_index_table[minidx - 1 + 4 * (tan(map_info->ver_angle) < 0)];
	if (edges[minidx - 1] < edges[(minidx + 1) % 4])
		idx += 4;
			snprintf(buf, 99, "oct: %d  y0x0:%6.2lf  y0x1:%6.2lf  y1x1:%6.2lf  y1x0:%6.2lf",
			idx, edges[0], edges[1], edges[2], edges[3]);
	map_info->carry = buf;
	return (idx);
}
*/
