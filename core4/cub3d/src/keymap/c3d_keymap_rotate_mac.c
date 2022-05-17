/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_keymap_rotate_mac.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:18:52 by hseong            #+#    #+#             */
/*   Updated: 2022/05/18 06:42:49 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_keymap.h"

// require MacOS Keycode
void	rotate_ccw(t_mlx_info *mlx_info)
{
	mlx_info->camera->angle -= YAW_STEP;
}

void	rotate_cw(t_mlx_info *mlx_info)
{
	mlx_info->camera->angle += YAW_STEP;
}
/*
void	rotate_rpitch(t_mlx_info *mlx_info)
{
	mlx_info->map_info->ver_angle -= ROLL_STEP;
}

void	rotate_pitch(t_mlx_info *mlx_info)
{
	mlx_info->map_info->ver_angle += ROLL_STEP;
}
*/
