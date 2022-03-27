/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_wireframe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:31:10 by hseong            #+#    #+#             */
/*   Updated: 2022/03/27 20:57:01 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	loop_diagonal(t_img_elem *img_elem, t_map *map);
static void	loop_grid(t_img_elem *img_elem, t_map *map);

void	fdf_wireframe(t_img_elem *img_elem, t_map *map)
{
	t_vertex	**map_arr;
	int			x;
	int			y;

	map_arr = map->map_arr;
	y = 0;
	x = map->col - 1;
	while (y < map->row - 1)
	{
		fdf_aa_drawline(img_elem, map_arr[y] + x, map_arr[y + 1] + x);
		++y;
	}
	if (map->colored == TRUE)
		loop_diagonal(img_elem, map);
	else
		loop_grid(img_elem, map);
	y = map->row - 1;
	x = 0;
	while (x < map->col - 1)
	{
		fdf_aa_drawline(img_elem, map_arr[y] + x, map_arr[y] + x + 1);
		++x;
	}
}

static void	loop_diagonal(t_img_elem *img_elem, t_map *map)
{
	t_vertex	**map_arr;
	int			x;
	int			y;

	map_arr = map->map_arr;
	x = map->col - 2;
	while (x >= 0)
	{
		y = 0;
		while (y < map->row - 1)
		{
			fdf_aa_drawline(img_elem, map_arr[y + 1] + x, map_arr[y] + x + 1);
			fdf_aa_drawline(img_elem, map_arr[y] + x, map_arr[y] + x + 1);
			fdf_aa_drawline(img_elem, map_arr[y] + x, map_arr[y + 1] + x);
			++y;
		}
		--x;
	}
}

static void	loop_grid(t_img_elem *img_elem, t_map *map)
{
	t_vertex	**map_arr;
	int			x;
	int			y;

	map_arr = map->map_arr;
	y = 0;
	while (y < map->row - 1)
	{
		x = map->col - 2;
		while (x >= 0)
		{
			fdf_aa_drawline(img_elem, map_arr[y] + x, map_arr[y] + x + 1);
			fdf_aa_drawline(img_elem, map_arr[y] + x, map_arr[y + 1] + x);
			--x;
		}
		++y;
	}
}
