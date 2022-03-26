/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_align_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:54:32 by hseong            #+#    #+#             */
/*   Updated: 2022/03/26 17:14:42 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_align_map(t_map *map)
{
	int		y_diff;
	int		x_diff;

	map->dx = SCREEN_WIDTH / (10 + map->row * 4 / 3);
	map->dz = SCREEN_HEIGHT / (10 + map->col * 5 / 3);
	map->x0 = SCREEN_WIDTH / 2;
	map->y0 = SCREEN_HEIGHT / 2;
	x_diff = map->dx * (map->row + map->col) / 4;
	if (map->row > map->col)
		y_diff = map->dx * (map->row - map->col) / 4;
	else
		y_diff = map->dx * (map->col - map->row) / 4;
	map->x0 -= x_diff;
	map->y0 += y_diff;
}
