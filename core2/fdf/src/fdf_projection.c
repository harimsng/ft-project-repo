/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:48:11 by hseong            #+#    #+#             */
/*   Updated: 2022/03/24 20:32:57 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	transform_point(t_map *map, t_point *point);

void	fdf_projection(t_mlx_info *mlx_info)
{
	t_point	**map_arr;
	t_map	*map;
	int		x;
	int		y;

	map = mlx_info->map;
	map_arr = map->map;
	y = 0;
	while (y < map->row)
	{
		x = 0;
		while (x < map->col)
		{
			transform_point(map, map_arr[y] + x);
			++x;
		}
		++y;
	}
}

static void	transform_point(t_map *map, t_point *point)
{
	double	x;
	double	y;
	double	z;

	x = (double)(point->x * map->dx);
	y = (double)(point->y * map->dx);
	z = (double)(point->z * map->dz);
	point->x = lround(sin(M_PI_4) * y + cos(M_PI_4) * x);
	y = cos(M_PI_4) * y - sin(M_PI_4) * x;
	point->z = lround(cos(MAGIC_ANGLE) * z - sin(MAGIC_ANGLE) * y);
	point->y = lround(sin(MAGIC_ANGLE) * z + cos(MAGIC_ANGLE) * y);
	point->y = -point->z;
	point->x += map->x0;
	point->y += map->y0;
}
