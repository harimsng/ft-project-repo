/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_wireframe_normal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:11:56 by hseong            #+#    #+#             */
/*   Updated: 2022/03/29 16:12:24 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_render_order.h"

void	render_n0(t_img_elem *img_elem, t_map_info *map_info, t_draw draw)
{
	t_vertex	**map_arr;
	int			x;
	int			y;

	map_arr = map_info->map_arr;
	x = map_info->col - 1;
	while (x > 0)
	{
		y = 0;
		while (y < map_info->row - 1)
		{
			draw(img_elem, map_arr[y] + x, map_arr[y] + x - 1);
			draw(img_elem, map_arr[y] + x, map_arr[y + 1] + x);
			++y;
		}
		draw(img_elem, map_arr[y] + x, map_arr[y] + x - 1);
		--x;
	}
	y = 0;
	while (y < map_info->row - 1)
	{
		draw(img_elem, map_arr[y], map_arr[y + 1]);
		++y;
	}
}

void	render_n1(t_img_elem *img_elem, t_map_info *map_info, t_draw draw)
{
	t_vertex	**map_arr;
	int			x;
	int			y;

	map_arr = map_info->map_arr;
	y = 0;
	while (y < map_info->row - 1)
	{
		x = 0;
		while (x < map_info->col - 1)
		{
			draw(img_elem, map_arr[y] + x, map_arr[y] + x + 1);
			draw(img_elem, map_arr[y] + x, map_arr[y + 1] + x);
			++x;
		}
		draw(img_elem, map_arr[y] + x, map_arr[y + 1] + x);
		++y;
	}
	x = 0;
	while (x < map_info->col - 1)
	{
		draw(img_elem, map_arr[y] + x, map_arr[y] + x + 1);
		++x;
	}
}

void	render_n2(t_img_elem *img_elem, t_map_info *map_info, t_draw draw)
{
	t_vertex	**map_arr;
	int			x;
	int			y;

	map_arr = map_info->map_arr;
	y = map_info->row - 1;
	while (y > 0)
	{
		x = map_info->col - 1;
		while (x > 0)
		{
			draw(img_elem, map_arr[y] + x, map_arr[y] + x - 1);
			draw(img_elem, map_arr[y] + x, map_arr[y - 1] + x);
			--x;
		}
		draw(img_elem, map_arr[y] + x, map_arr[y - 1] + x);
		--y;
	}
	x = map_info->col - 1;
	while (x > 0)
	{
		draw(img_elem, map_arr[y] + x, map_arr[y] + x - 1);
		--x;
	}
}

void	render_n3(t_img_elem *img_elem, t_map_info *map_info, t_draw draw)
{
	t_vertex	**map_arr;
	int			x;
	int			y;

	map_arr = map_info->map_arr;
	x = 0;
	while (x < map_info->col - 1)
	{
		y = map_info->row - 1;
		while (y > 0)
		{
			draw(img_elem, map_arr[y] + x, map_arr[y] + x + 1);
			draw(img_elem, map_arr[y] + x, map_arr[y - 1] + x);
			--y;
		}
		draw(img_elem, map_arr[y] + x, map_arr[y] + x + 1);
		++x;
	}
	y = map_info->row - 1;
	while (y > 0)
	{
		draw(img_elem, map_arr[y] + x, map_arr[y - 1] + x);
		--y;
	}
}
