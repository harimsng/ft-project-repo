/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_wireframe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:31:10 by hseong            #+#    #+#             */
/*   Updated: 2022/03/23 20:56:21 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_type.h"

void	fdf_wireframe(t_img_elem *img_elem, t_map *map)
{
	t_point	**map_arr;
	int		x;
	int		y;

	map_arr = map->map;
	x = 0;
	while (x < map->row - 1)
	{
		y = 0;
		while (y < map->col - 1)
		{
			fdf_drawline(img_elem, map_arr[x] + y, map_arr[x] + y + 1);
			fdf_drawline(img_elem, map_arr[x] + y, map_arr[x + 1] + y);
			++y;
		}
		++x;
	}
	x = 0;
	while (x < map->row - 1)
	{
		fdf_drawline(img_elem, map_arr[x] + y, map_arr[x + 1] + y);
		++x;
	}
	y = 0;
	while (y < map->col - 1)
	{
		fdf_drawline(img_elem, map_arr[x] + y, map_arr[x] + y + 1);
		++y;
	}

}
