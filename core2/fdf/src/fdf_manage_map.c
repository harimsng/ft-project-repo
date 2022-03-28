/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_manage_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:31:12 by hseong            #+#    #+#             */
/*   Updated: 2022/03/28 20:40:34 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// align map to the center of the display.
// y coordinate is higher(lower in the display) than mid-value.
void	fdf_align_map(t_map_info *map_info)
{
	map_info->hor_angle = HOR_ANGLE;
	map_info->ver_angle = VER_ANGLE;
	map_info->hor_scale = (double)SCREEN_WIDTH
			/ (map_info->col + map_info->row);
	map_info->ver_scale = (double)SCREEN_HEIGHT
			/ (double)(map_info->col + map_info->row + map_info->max_height / 2);
	map_info->x0 = SCREEN_WIDTH / 2;
	map_info->y0 = SCREEN_HEIGHT * 10 / 19;
}

void	fdf_alloc_map(t_map_info *map_info)
{
	t_vertex	**projected;
	int			idx;

	projected = malloc(sizeof(t_vertex *) * map_info->row);
	idx = 0;
	while (idx < map_info->row)
	{
		projected[idx] = malloc(sizeof(t_vertex) * map_info->col);
		++idx;
	}
	map_info->map_arr = projected;
}
