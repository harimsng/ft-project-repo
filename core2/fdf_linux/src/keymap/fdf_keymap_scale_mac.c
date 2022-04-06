/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keymap_scale_mac.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:21:17 by hseong            #+#    #+#             */
/*   Updated: 2022/04/05 11:58:12 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_keymap.h"

// require MacOS Keycode
void	scale_up(t_mlx_info *mlx_info)
{
	if (mlx_info->map_info->hor_scale
		+ (mlx_info->map_info->row + mlx_info->map_info->col) > VP_DIST << 4)
		return ;
	mlx_info->map_info->x0
		= (mlx_info->map_info->x0 - SCREEN_WIDTH / 2.0)
		* SCALE_STEP + SCREEN_WIDTH / 2.0;
	mlx_info->map_info->y0
		= (mlx_info->map_info->y0 - SCREEN_HEIGHT / 2.0)
		* SCALE_STEP + SCREEN_HEIGHT / 2.0;
	mlx_info->map_info->hor_scale *= SCALE_STEP;
	mlx_info->map_info->ver_scale *= SCALE_STEP;
}

void	scale_down(t_mlx_info *mlx_info)
{
	if (mlx_info->map_info->hor_scale < 1.0)
		return ;
	mlx_info->map_info->x0
		= (mlx_info->map_info->x0 - SCREEN_WIDTH / 2.0)
		/ SCALE_STEP + SCREEN_WIDTH / 2.0;
	mlx_info->map_info->y0
		= (mlx_info->map_info->y0 - SCREEN_HEIGHT / 2.0)
		/ SCALE_STEP + SCREEN_HEIGHT / 2.0;
	mlx_info->map_info->hor_scale /= SCALE_STEP;
	mlx_info->map_info->ver_scale /= SCALE_STEP;
}
