/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keymap1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:44:24 by hseong            #+#    #+#             */
/*   Updated: 2022/03/28 20:43:59 by hseong           ###   ########.fr       */
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
	mlx_info->map_info->hor_scale *= 1.2;
	mlx_info->map_info->ver_scale *= 1.2;
	if (mlx_info->map_info->hor_scale > 1000)
		mlx_info->map_info->hor_scale = 1000;
	if (mlx_info->map_info->ver_scale > 1000)
		mlx_info->map_info->ver_scale = 1000;
}

void	scale_down(t_mlx_info *mlx_info)
{
	mlx_info->map_info->hor_scale /= 1.2;
	mlx_info->map_info->ver_scale /= 1.2;
	if (mlx_info->map_info->hor_scale < 1)
		mlx_info->map_info->hor_scale = 1;
	if (mlx_info->map_info->ver_scale < 1)
		mlx_info->map_info->ver_scale = 1;
}

void	set_default(t_mlx_info *mlx_info)
{
	t_map_info	*map_info;

	map_info = mlx_info->map_info;
	map_info->hor_angle = HOR_ANGLE;
	map_info->ver_angle = VER_ANGLE;
	map_info->x0 = SCREEN_WIDTH / 2;
	map_info->y0 = SCREEN_HEIGHT * 10 / 19;
}
