/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_align_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:54:32 by hseong            #+#    #+#             */
/*   Updated: 2022/03/24 18:31:31 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_align_map(t_map *map)
{
	int		y_diff;
	int		x_diff;

	if (map->dx == 0 || map->dz == 0)
	{
		map->dx = SCREEN_WIDTH / (10 * sqrt(map->row / 2) + log(map->row));
		map->dz = SCREEN_HEIGHT / (10 * sqrt(map->col / 2) + log(map->col));
	}
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
