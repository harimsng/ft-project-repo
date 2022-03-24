/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_wireframe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:31:10 by hseong            #+#    #+#             */
/*   Updated: 2022/03/24 22:00:45 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_wireframe(t_img_elem *img_elem, t_map *map)
{
	t_point	**map_arr;
	int		x;
	int		y;

	map_arr = map->map;
	x = map->row - 1;
	y = 0;
	while (y < map->col - 1)
	{
		fdf_drawline(img_elem, map_arr[x] + y, map_arr[x] + y + 1);
		++y;
	}
	x = 0;
	y = map->col - 1;
	while (x < map->row - 1)
	{
		fdf_drawline(img_elem, map_arr[x] + y, map_arr[x + 1] + y);
		++x;
	}
	x = 0;
	while (x < map->row - 1)
	{
		y = 0;
		while (y < map->col - 1)
		{
			if (map->colored == TRUE)
				fdf_drawline(img_elem, map_arr[x + 1] + y, map_arr[x] + y + 1);
			fdf_drawline(img_elem, map_arr[x] + y, map_arr[x] + y + 1);
			fdf_drawline(img_elem, map_arr[x] + y, map_arr[x + 1] + y);
			++y;
		}
		++x;
	}
	x = 0;
}
