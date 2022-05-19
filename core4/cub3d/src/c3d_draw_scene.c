/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_draw_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:39:33 by hseong            #+#    #+#             */
/*   Updated: 2022/05/19 18:05:54 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"
#include "c3d_const.h"
#include <math.h>

void
c3d_draw_scene(t_mlx_info *mlx_info, t_camera *camera, int count, double dist)
{
	t_pixel	*map;
	size_t	hor_px;
	size_t	idx;
	size_t	len;
	int		color;

	(void)camera;
	if ((int)dist >= MAX_DIST)
		return ;
	map = mlx_info->img_elem->img_buf;
	len = 2 * GRID_WIDTH * VP_DIST / dist;
	idx = (SCREEN_HEIGHT - len) >> 1;
	if (idx + len >= SCREEN_HEIGHT)
	{
		idx = 0;
		len = SCREEN_HEIGHT;
	}
	hor_px = mlx_info->img_elem->hor_px;
	color = 0xFF * (1.0 - 2 * dist / (MAX_DIST + dist));
	color = (color << 16) + (color << 8) + color;
	while (len)
	{
		map[idx * hor_px + count] = color;
		++idx;
		--len;
	}

}
