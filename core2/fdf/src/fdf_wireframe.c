/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_wireframe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:31:10 by hseong            #+#    #+#             */
/*   Updated: 2022/04/01 14:19:41 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_render_order.h"

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
