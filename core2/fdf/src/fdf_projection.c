/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:48:11 by hseong            #+#    #+#             */
/*   Updated: 2022/03/29 18:52:03 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	transform_point(t_map_info *map_info, t_vertex *to, t_vertex *from);

void	fdf_projection(t_mlx_info *mlx_info)
{
	t_vertex	**map_arr;
	t_vertex	**map_origin;
	t_map_info	*map_info;
	int			x;
	int			y;

	map_info = mlx_info->map_info;
	map_arr = map_info->map_arr;
	map_origin = map_info->map_origin;
	y = 0;
	while (y < map_info->row)
	{
		x = 0;
		while (x < map_info->col)
		{
			transform_point(map_info, map_arr[y] + x, map_origin[y] + x);
			map_arr[y][x].color = map_origin[y][x].color;
			++x;
		}
		++y;
	}
}

static void	transform_point(t_map_info *map_info, t_vertex *to, t_vertex *from)
{
	double	x;
	double	y;
	double	z;

	x = from->x * (double)map_info->hor_scale;
	y = from->y * (double)map_info->hor_scale;
	z = from->z * (double)map_info->ver_scale;
	to->x = (sin(map_info->hor_angle) * y + cos(map_info->hor_angle) * x);
	to->y = (-cos(map_info->ver_angle) * z
			+ (sin(map_info->ver_angle) * cos(map_info->hor_angle)) * y
			- (sin(map_info->ver_angle) * sin(map_info->hor_angle)) * x);
	to->x += (double)map_info->x0;
	to->y += (double)map_info->y0;
}
