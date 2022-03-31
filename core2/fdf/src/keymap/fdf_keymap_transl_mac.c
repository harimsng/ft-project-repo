/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keymap_transl_mac.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:22:23 by hseong            #+#    #+#             */
/*   Updated: 2022/03/29 18:22:29 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_keymap.h"
#include "fdf_const.h"

// require MacOS Keycode
void	move_obj_left(t_mlx_info *mlx_info)
{
	mlx_info->map_info->x0 += mlx_info->map_info->hor_scale * X_STEP;
}

void	move_obj_right(t_mlx_info *mlx_info)
{
	mlx_info->map_info->x0 -= mlx_info->map_info->hor_scale * X_STEP;
}

void	move_obj_up(t_mlx_info *mlx_info)
{
	mlx_info->map_info->y0 += mlx_info->map_info->hor_scale * Y_STEP;
}

void	move_obj_down(t_mlx_info *mlx_info)
{
	mlx_info->map_info->y0 -= mlx_info->map_info->hor_scale * Y_STEP;
}