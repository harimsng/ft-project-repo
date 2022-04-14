/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keymap_scale_mac.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:21:17 by hseong            #+#    #+#             */
/*   Updated: 2022/04/13 13:50:47 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_keymap.h"
#include "fdf_const.h"

// require MacOS Keycode
void	scale_up(t_mlx_info *mlx_info)
{
	t_map_info	*map_info;

	map_info = mlx_info->map_info;
//	if (map_info->hor_scale
//		+ (map_info->row + map_info->col) > VP_DIST << 4)
//		return ;
	map_info->var_x *= SCALE_STEP;
	map_info->var_y *= SCALE_STEP;
	map_info->hor_scale *= SCALE_STEP;
	map_info->ver_scale *= SCALE_STEP;
}

void	scale_down(t_mlx_info *mlx_info)
{
	t_map_info	*map_info;

	map_info = mlx_info->map_info;
//	if (mlx_info->map_info->hor_scale < 1.0)
//		return ;
	map_info->var_x /= SCALE_STEP;
	map_info->var_y /= SCALE_STEP;
	map_info->hor_scale /= SCALE_STEP;
	map_info->ver_scale /= SCALE_STEP;
}
