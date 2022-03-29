/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keymap_scale_mac.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:21:17 by hseong            #+#    #+#             */
/*   Updated: 2022/03/29 18:24:26 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_keymap.h"
#include "fdf_const.h"

// require MacOS Keycode
void	scale_up(t_mlx_info *mlx_info)
{
	if (mlx_info->map_info->hor_scale > 300.0)
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

void	set_default(t_mlx_info *mlx_info)
{
	t_map_info	*map_info;

	map_info = mlx_info->map_info;
	map_info->hor_scale = (double)SCREEN_WIDTH
		/ (map_info->col + map_info->row);
	map_info->ver_scale = (double)SCREEN_HEIGHT
		/ (map_info->col + map_info->row + map_info->max_height / 2.0);
	map_info->hor_angle = HOR_ANGLE;
	map_info->ver_angle = VER_ANGLE;
	map_info->x0 = SCREEN_WIDTH / 2;
	map_info->y0 = SCREEN_HEIGHT * 10 / 19;
}
