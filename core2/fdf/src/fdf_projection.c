/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:48:11 by hseong            #+#    #+#             */
/*   Updated: 2022/03/31 22:36:31 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_transform.h"

typedef void			(*t_transf)(t_map_info *, t_vertex *, t_vertex *);

static const t_transf	g_transform[2]
	= {
	isometric_proj,
	perspective_proj
};

void	fdf_projection(t_map_info *map_info)
{
	t_transf	transform;
	int			x;
	int			y;

	transform = g_transform[map_info->projection];
	y = 0;
	while (y < map_info->row)
	{
		x = 0;
		while (x < map_info->col)
		{
			transform(map_info, map_info->map_proj[y] + x,
				map_info->map_origin[y] + x);
			map_info->map_proj[y][x].color = map_info->map_origin[y][x].color;
			++x;
		}
		++y;
	}
}

void	isometric_proj(t_map_info *map_info, t_vertex *to, t_vertex *from)
{
	double	x;
	double	y;
	double	z;

	x = from->x * (double)map_info->hor_scale;
	y = -from->z * (double)map_info->ver_scale;
	z = from->y * (double)map_info->hor_scale;
	to->x = sin(map_info->hor_angle) * z + cos(map_info->hor_angle) * x;
	to->y = cos(map_info->ver_angle) * y
		+ sin(map_info->ver_angle) * cos(map_info->hor_angle) * z
		- sin(map_info->ver_angle) * sin(map_info->hor_angle) * x;
	y = to->y;
	x = to->x;
	to->y = cos(map_info->gamma) * y - sin(map_info->gamma) * x;
	to->x = sin(map_info->gamma) * y + cos(map_info->gamma) * x;
	to->x += (double)map_info->x0;
	to->y += (double)map_info->y0;
}

//to->z += map_info->row + map_info->col :
//	relative position between camera.
//	it causes problem when they are close.
void	perspective_proj(t_map_info *map_info, t_vertex *to, t_vertex *from)
{
	double	x;
	double	y;
	double	z;

	x = from->x * (double)map_info->hor_scale;
	y = -from->z * (double)map_info->ver_scale;
	z = from->y * (double)map_info->hor_scale;
	to->x += (double)map_info->x0;
	to->y += (double)map_info->y0;
	to->x = sin(map_info->hor_angle) * z + cos(map_info->hor_angle) * x;
	z = cos(map_info->hor_angle) * z - sin(map_info->hor_angle) * x;
	to->y = sin(map_info->ver_angle) * z + cos(map_info->ver_angle) * y;
	to->z = cos(map_info->ver_angle) * z - sin(map_info->ver_angle) * y;
	to->z *= -1;
	to->z += VP_DIST;
	if (to->z < 0)
		to->z = -1;
	to->x *= VP_DIST / to->z;
	to->y *= VP_DIST / to->z;
}
