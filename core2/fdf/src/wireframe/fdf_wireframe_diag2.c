/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_wireframe_diag2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:21:17 by hseong            #+#    #+#             */
/*   Updated: 2022/03/31 22:11:57 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_render_order.h"

void	render_d4(t_img_elem *img_elem, t_map_info *map_info, t_draw draw)
{
	t_vertex	**map_proj;
	int			x;
	int			y;

	map_proj = map_info->map_proj;
	y = 0;
	while (y < map_info->row - 1)
	{
		x = map_info->col - 1;
		while (x > 0)
		{
			draw(img_elem, map_proj[y] + x, map_proj[y + 1] + x - 1);
			draw(img_elem, map_proj[y] + x, map_proj[y] + x - 1);
			draw(img_elem, map_proj[y] + x, map_proj[y + 1] + x);
			--x;
		}
		draw(img_elem, map_proj[y], map_proj[y + 1]);
		++y;
	}
	x = map_info->col - 1;
	while (x > 0)
	{
		draw(img_elem, map_proj[y] + x, map_proj[y] + x - 1);
		--x;
	}
}

void	render_d5(t_img_elem *img_elem, t_map_info *map_info, t_draw draw)
{
	t_vertex	**map_proj;
	int			x;
	int			y;

	map_proj = map_info->map_proj;
	x = 0;
	while (x < map_info->col - 1)
	{
		y = 0;
		while (y < map_info->row - 1)
		{
			draw(img_elem, map_proj[y + 1] + x, map_proj[y] + x + 1);
			draw(img_elem, map_proj[y] + x, map_proj[y] + x + 1);
			draw(img_elem, map_proj[y + 1] + x, map_proj[y] + x);
			++y;
		}
		draw(img_elem, map_proj[y] + x, map_proj[y] + x + 1);
		++x;
	}
	y = 0;
	while (y < map_info->row - 1)
	{
		draw(img_elem, map_proj[y + 1] + x, map_proj[y] + x);
		++y;
	}
}

void	render_d6(t_img_elem *img_elem, t_map_info *map_info, t_draw draw)
{
	t_vertex	**map_proj;
	int			x;
	int			y;

	map_proj = map_info->map_proj;
	x = map_info->col - 1;
	while (x > 0)
	{
		y = map_info->row - 1;
		while (y > 0)
		{
			draw(img_elem, map_proj[y - 1] + x, map_proj[y] + x - 1);
			draw(img_elem, map_proj[y] + x, map_proj[y] + x - 1);
			draw(img_elem, map_proj[y] + x, map_proj[y - 1] + x);
			--y;
		}
		draw(img_elem, map_proj[y] + x, map_proj[y] + x - 1);
		--x;
	}
	y = map_info->row - 1;
	while (y > 0)
	{
		draw(img_elem, map_proj[y] + x, map_proj[y - 1] + x);
		--y;
	}
}

void	render_d7(t_img_elem *img_elem, t_map_info *map_info, t_draw draw)
{
	t_vertex	**map_proj;
	int			x;
	int			y;

	map_proj = map_info->map_proj;
	y = map_info->row - 1;
	while (y > 0)
	{
		x = 0;
		while (x < map_info->col - 1)
		{
			draw(img_elem, map_proj[y] + x, map_proj[y - 1] + x + 1);
			draw(img_elem, map_proj[y] + x, map_proj[y] + x + 1);
			draw(img_elem, map_proj[y] + x, map_proj[y - 1] + x);
			++x;
		}
		draw(img_elem, map_proj[y] + x, map_proj[y - 1] + x);
		--y;
	}
	x = 0;
	while (x < map_info->col - 1)
	{
		draw(img_elem, map_proj[y] + x, map_proj[y] + x + 1);
		++x;
	}
}
