/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:48:11 by hseong            #+#    #+#             */
/*   Updated: 2022/04/15 02:04:01 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_transform.h"
#include "fdf_complex.h"
#include "fdf_colors.h"
#include <math.h>

typedef void			(*t_transf)(t_map_info *, t_vertex *, t_vertex *);

static void	*transform_wrapper(void *arg);

static const t_transf	g_transform[2]
	= {
	isometric_proj,
	perspective_proj
};

static t_map_info		*g_map_info;

void	fdf_projection(t_map_info *map_info, pthread_t *thread)
{
	//t_transf	transform;
	//int			x;
	int			y;
	int			y_arr[SCREEN_HEIGHT];

	g_map_info = map_info;
	//transform = g_transform[map_info->projection];
	y = 0;
	while (y < map_info->row)
	{
		y_arr[y] = y;
		pthread_create(thread + y, NULL, transform_wrapper, y_arr + y);
/*
		x = 0;
		while (x < map_info->col)
		{
			transform(map_info, map_info->map_proj[y] + x,
				map_info->map_origin[y] + x);
			map_info->map_proj[y][x].color = map_info->map_origin[y][x].color;
			++x;
		}
*/
		++y;
	}
}

void	*transform_wrapper(void *arg)
{
	int			x;
	int			y;
	int			hcol;
	int			hrow;
	t_pixel		color;

	hcol = g_map_info->col >> 1;
	hrow = g_map_info->row >> 1;
	y = *(int *)arg;
	x = 0;
	while (x < g_map_info->col)
	{
		color = fdf_fractal(((double)x - hcol - g_map_info->var_x) / hcol,
			((double)y - hrow - g_map_info->var_y) / hrow, g_map_info);
		g_map_info->map_origin[y][x].z
			= color * g_map_info->max_height / FRACT_MAXITER;
		g_transform[g_map_info->projection](g_map_info,
			g_map_info->map_proj[y] + x, g_map_info->map_origin[y] + x);
		g_map_info->map_proj[y][x].color = g_color_arr[color + 220];
//		g_map_info->map_proj[y][x].color = 0xD00000 + color + (color << 8);
		++x;
	}
	return (NULL);
}

void	isometric_proj(t_map_info *map_info, t_vertex *to, t_vertex *from)
{
	double	x;
	double	y;
	double	z;

	x = from->x * (double)map_info->hor_scale;
	y = -from->z * (double)map_info->ver_scale;
	z = from->y * (double)map_info->hor_scale;
	y += map_info->var_height;
	to->x = sin(map_info->hor_angle) * z + cos(map_info->hor_angle) * x;
	to->y = cos(map_info->ver_angle) * y
		+ sin(map_info->ver_angle) * cos(map_info->hor_angle) * z
		- sin(map_info->ver_angle) * sin(map_info->hor_angle) * x;
	y = to->y;// + map_info->var_y;
	x = to->x;// + map_info->var_x;
	to->y = cos(map_info->gamma) * y - sin(map_info->gamma) * x;
	to->x = sin(map_info->gamma) * y + cos(map_info->gamma) * x;
	to->x += (double)map_info->x0;
	to->y += (double)map_info->y0;
}

void	perspective_proj(t_map_info *map_info, t_vertex *to, t_vertex *from)
{
	double	x;
	double	y;
	double	z;

	x = from->x * (double)map_info->hor_scale;
	y = -from->z * (double)map_info->ver_scale;
	z = from->y * (double)map_info->hor_scale;
	y += map_info->var_height;
	to->x = sin(map_info->hor_angle) * z + cos(map_info->hor_angle) * x
;//		+ map_info->var_x;
	z = cos(map_info->hor_angle) * z - sin(map_info->hor_angle) * x
;//		+ map_info->var_y;
	to->y = sin(map_info->ver_angle) * z + cos(map_info->ver_angle) * y;
	to->z = cos(map_info->ver_angle) * z - sin(map_info->ver_angle) * y;
	to->z *= -1;
	to->z += VP_DIST;
	if (to->z < 0)
		to->z = -1;
	to->x *= VP_DIST / to->z;
	to->y *= VP_DIST / to->z;
	to->x += (double)map_info->x0;
	to->y += (double)map_info->y0;
}
