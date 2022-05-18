/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_draw_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:39:33 by hseong            #+#    #+#             */
/*   Updated: 2022/05/18 22:27:22 by hseong           ###   ########.fr       */
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
	map = mlx_info->img_elem->img_buf;
	len = GRID_WIDTH * VP_DIST / dist * 2;
	idx = (SCREEN_HEIGHT - len) / 2;
	if (idx + len >= SCREEN_HEIGHT)
		return ;
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
