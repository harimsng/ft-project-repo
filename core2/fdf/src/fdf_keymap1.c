/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keymap1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:44:24 by hseong            #+#    #+#             */
/*   Updated: 2022/03/28 17:19:55 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_keymap.h"

void	move_obj_left(t_mlx_info *mlx_info)
{
	mlx_info->map_info->x0 -= X_STEP;
}

void	move_obj_right(t_mlx_info *mlx_info)
{
	mlx_info->map_info->x0 += X_STEP;
}

void	move_obj_up(t_mlx_info *mlx_info)
{
	mlx_info->map_info->y0 -= Y_STEP;
}

void	move_obj_down(t_mlx_info *mlx_info)
{
	mlx_info->map_info->y0 += Y_STEP;
}

void	rotate_ccw(t_mlx_info *mlx_info)
{
	mlx_info->map_info->hor_angle += YAW_STEP;
}

void	rotate_cw(t_mlx_info *mlx_info)
{
	mlx_info->map_info->hor_angle -= YAW_STEP;
}

void	rotate_roll(t_mlx_info *mlx_info)
{
	mlx_info->map_info->ver_angle -= ROLL_STEP;
}

void	rotate_rroll(t_mlx_info *mlx_info)
{
	mlx_info->map_info->ver_angle += ROLL_STEP;
}

void	scale_up(t_mlx_info *mlx_info)
{
	mlx_info->map_info->hor_scale += SCALE_STEP;
	mlx_info->map_info->ver_scale += SCALE_STEP;
}

void	scale_down(t_mlx_info *mlx_info)
{
	mlx_info->map_info->hor_scale -= SCALE_STEP;
	mlx_info->map_info->ver_scale -= SCALE_STEP;
}
