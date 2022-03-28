/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_wireframe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:31:10 by hseong            #+#    #+#             */
/*   Updated: 2022/03/28 19:51:30 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef void	(*t_draw)(t_img_elem *, t_vertex *, t_vertex *);

static void	loop_diagonal(t_img_elem *img_elem, t_map_info *map_info,
				t_draw draw);
static void	loop_grid(t_img_elem *img_elem, t_map_info *map_info, t_draw draw);

void	fdf_wireframe(t_img_elem *img_elem, t_map_info *map_info)
{
	t_vertex	**map_arr;
	t_draw		draw;
	int			x;
	int			y;

	draw = fdf_drawline;
	if (map_info->hor_scale > 16)
		draw = fdf_aa_drawline;
	map_arr = map_info->map_arr;
	y = -1;
	x = map_info->col - 1;
	while (++y < map_info->row - 1)
		draw(img_elem, map_arr[y] + x, map_arr[y + 1] + x);
	if (map_info->colored == TRUE)
		loop_diagonal(img_elem, map_info, draw);
	else
		loop_grid(img_elem, map_info, draw);
	x = -1;
	while (++x < map_info->col - 1)
		draw(img_elem, map_arr[y] + x, map_arr[y] + x + 1);
}

void	loop_diagonal(t_img_elem *img_elem, t_map_info *map_info, t_draw draw)
{
	t_vertex	**map_arr;
	int			x;
	int			y;

	map_arr = map_info->map_arr;
	x = map_info->col - 2;
	while (x >= 0)
	{
		y = 0;
		while (y < map_info->row - 1)
		{
			draw(img_elem, map_arr[y + 1] + x, map_arr[y] + x + 1);
			draw(img_elem, map_arr[y] + x, map_arr[y] + x + 1);
			draw(img_elem, map_arr[y] + x, map_arr[y + 1] + x);
			++y;
		}
		--x;
	}
}

void	loop_grid(t_img_elem *img_elem, t_map_info *map_info, t_draw draw)
{
	t_vertex	**map_arr;
	int			x;
	int			y;

	map_arr = map_info->map_arr;
	y = 0;
	while (y < map_info->row - 1)
	{
		x = map_info->col - 2;
		while (x >= 0)
		{
			draw(img_elem, map_arr[y] + x, map_arr[y] + x + 1);
			draw(img_elem, map_arr[y] + x, map_arr[y + 1] + x);
			--x;
		}
		++y;
	}
}
