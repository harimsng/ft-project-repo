/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:48:11 by hseong            #+#    #+#             */
/*   Updated: 2022/03/24 17:57:01 by hseong           ###   ########.fr       */
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
	int		x;
	int		y;
	int		z;

	if (point->z != 0)
		point->color = 0x00FF0000;
	x = point->x * map->dx;
	y = point->y * map->dx;
	point->x = cos(M_PI_4) * x + sin(M_PI_4) * y;
	point->y = -sin(M_PI_4) * x + cos(M_PI_4) * y;
	y = point->y;
	z = point->z * map->dz;
	point->z = cos(MAGIC_ANGLE) * z - sin(MAGIC_ANGLE) * y;
	point->y = sin(MAGIC_ANGLE) * z + cos(MAGIC_ANGLE) * y;
	point->y = -point->z;
	point->x += map->x0;
	point->y += map->y0;
}
