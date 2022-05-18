/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_background.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 07:37:53 by hseong            #+#    #+#             */
/*   Updated: 2022/05/19 00:09:08 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"
#include "c3d_const.h"

void	c3d_background(t_mlx_info *mlx_info)
{
	t_map_info	*map_info;
	t_img_elem	*img_elem;
	size_t		idx;
	size_t		jdx;

	map_info = mlx_info->map_info;
	img_elem = mlx_info->img_elem;
	jdx = 0;
	while (jdx < SCREEN_HEIGHT && (jdx >> LOG_GRID_WIDTH) < map_info->row)
	{
		idx = 0;
		while (idx < SCREEN_WIDTH && (idx >> LOG_GRID_WIDTH) < map_info->col)
		{
			if (map_info->map[jdx >> LOG_GRID_WIDTH][idx >> LOG_GRID_WIDTH]
				== 1)
				img_elem->img_buf[jdx * img_elem->hor_px + idx] = 0xFFFFFF;
			++idx;
		}
		++jdx;
	}
}
