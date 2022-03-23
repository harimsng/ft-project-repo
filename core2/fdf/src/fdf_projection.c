/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:48:11 by hseong            #+#    #+#             */
/*   Updated: 2022/03/23 21:07:55 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_type.h"
#include "fdf_const.h"

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
			map_arr[y][x].x = 40;
			map_arr[y][x].y = 40;
			++x;
		}
		++y;
	}
}
