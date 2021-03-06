/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keymap_transl_mac.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:22:23 by hseong            #+#    #+#             */
/*   Updated: 2022/04/13 01:24:15 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_const.h"
#include "fdf_keymap.h"

// require MacOS Keycode
void	move_obj_left(t_mlx_info *mlx_info)
{
//	mlx_info->map_info->var_x -= mlx_info->map_info->hor_scale * X_STEP;
	mlx_info->map_info->var_x -= X_STEP;
}

void	move_obj_right(t_mlx_info *mlx_info)
{
//	mlx_info->map_info->var_x += mlx_info->map_info->hor_scale * X_STEP;
	mlx_info->map_info->var_x += X_STEP;
}

void	move_obj_forward(t_mlx_info *mlx_info)
{
//	mlx_info->map_info->var_y -= mlx_info->map_info->hor_scale * Y_STEP;
	mlx_info->map_info->var_y -= Y_STEP;
}

void	move_obj_back(t_mlx_info *mlx_info)
{
//	mlx_info->map_info->var_y += mlx_info->map_info->hor_scale * Y_STEP;
	mlx_info->map_info->var_y += Y_STEP;
}
