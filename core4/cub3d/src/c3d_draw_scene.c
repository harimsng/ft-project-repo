/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_draw_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:39:33 by hseong            #+#    #+#             */
/*   Updated: 2022/06/06 06:44:39 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

#include "c3d.h"
#include "c3d_const.h"

static t_uint32	darken_color(t_uint32 color, double dist);

void	c3d_draw_vline(int contact, t_mlx_info *mlx_info,
		int count, double dist)
{
	t_pixel	*map;
	size_t	idx;
	size_t	jdx;
	size_t	len;
	size_t	len_origin;
	size_t	hor_px;
//	int		color;
	t_img_elem	*texture = mlx_info->resource->attr_arr;

	if ((int)dist >= MAX_DIST)
		return ;
	map = mlx_info->img_elem->img_buf;
	hor_px = mlx_info->img_elem->hor_px;
	len = 2 * GRID_WIDTH * VP_DIST / dist;
	len_origin = len;
	idx = (SCREEN_HEIGHT - len) >> 1;
	jdx = 0;
	if (len >= SCREEN_HEIGHT)
	{
		idx = 0;
		len = SCREEN_HEIGHT;
		jdx = (len_origin - SCREEN_HEIGHT) / 2 ;
	}
	(void)darken_color;
	while (len)
	{
		map[idx * hor_px + count]
			= darken_color(texture->img_buf
//			[texture->hor_px * (jdx * texture->ver_px / len_origin)
//			+ (contact * texture->hor_px / GRID_WIDTH)];
			[(texture->line_bytes >> 2) * (jdx * texture->ver_px / len_origin)
			+ (contact & MASK_GRID_WIDTH)
			* (texture->hor_px >> LOG_GRID_WIDTH)], dist);
//			+ (contact % GRID_WIDTH) * texture->hor_px / GRID_WIDTH];
//			= darken_color(texture->img_buf
//			[jdx * texture->ver_px / len_origin * texture->hor_px
//			+ (contact % GRID_WIDTH) * texture->hor_px / GRID_WIDTH], dist);
		++idx;
		++jdx;
		--len;
	}
}
//	color = 0xFF * (1.0 - 2 * dist / (MAX_DIST + dist));
//	color = (color << 16) + (color << 8) + color;

t_uint32	darken_color(t_uint32 color, double dist)
{
	t_byte	red;
	t_byte	green;
	t_byte	blue;

	red = (color & 0xFF0000) >> 16;
	green = (color & 0xFF00) >> 8;
	blue = color & 0xFF;
	red = red * (1.0 - dist / (DARKEN_DIST + dist));
	green = green * (1.0 - dist / (DARKEN_DIST + dist));
	blue = blue * (1.0 - dist / (DARKEN_DIST + dist));
	return ((red << 16) + (green << 8) + blue);
}
