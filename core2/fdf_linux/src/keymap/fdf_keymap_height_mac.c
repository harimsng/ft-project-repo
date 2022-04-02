/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keymap_height_mac.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:28:23 by hseong            #+#    #+#             */
/*   Updated: 2022/04/01 19:44:53 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_keymap.h"

void	height_up(t_mlx_info *mlx_info)
{
	t_map_info	*map_info;
	double		*ver_scale;

	map_info = mlx_info->map_info;
	ver_scale = &mlx_info->map_info->ver_scale;
	*ver_scale += 20.0 / (map_info->col + map_info->row);
	if (*ver_scale < 0)
		*ver_scale /= SCALE_STEP;
	else
	{
		if (*ver_scale < 20.0 / (map_info->col + map_info->row))
			*ver_scale = 0.0;
		*ver_scale *= SCALE_STEP;
	}
}

void	height_down(t_mlx_info *mlx_info)
{
	t_map_info	*map_info;
	double		*ver_scale;

	map_info = mlx_info->map_info;
	ver_scale = &mlx_info->map_info->ver_scale;
	*ver_scale -= 20.0 / (map_info->col + map_info->row);
	if (*ver_scale > 0)
		*ver_scale /= SCALE_STEP;
	else
	{
		if (*ver_scale > -20.0 / (map_info->col + map_info->row))
			*ver_scale = 0.0;
		*ver_scale *= SCALE_STEP;
	}
}
