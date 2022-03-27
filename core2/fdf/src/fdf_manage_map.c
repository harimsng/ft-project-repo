/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_manage_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:31:12 by hseong            #+#    #+#             */
/*   Updated: 2022/03/27 18:46:51 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// align map to the center of the display.
// y coordinate is higher(lower in the display) than mid-value.
void	fdf_align_map(t_map *map)
{
	map->hor_scale = (double)SCREEN_WIDTH / (map->col + map->row);
	map->ver_scale = (double)SCREEN_HEIGHT
			/ (map->col + map->row + map->max_height / 2);
	map->x0 = SCREEN_WIDTH / 2;
	map->y0 = SCREEN_HEIGHT / 2;
	map->x0 -= map->hor_scale * (map->col + map->row)
		* cos(M_PI_4) * cos(MAGIC_ANGLE) / 2;
	map->y0 += map->hor_scale * (map->col + map->row)
		* cos(M_PI_4) * sin(MAGIC_ANGLE) / 4;
}

void	fdf_control_map(t_map *map)
{
	(void)map;
}
