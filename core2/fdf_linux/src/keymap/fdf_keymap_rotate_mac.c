/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keymap_rotate_mac.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:18:52 by hseong            #+#    #+#             */
/*   Updated: 2022/04/01 18:29:05 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_keymap.h"

// require MacOS Keycode
void	rotate_ccw(t_mlx_info *mlx_info)
{
	mlx_info->map_info->hor_angle += YAW_STEP;
}

void	rotate_cw(t_mlx_info *mlx_info)
{
	mlx_info->map_info->hor_angle -= YAW_STEP;
}

void	rotate_rpitch(t_mlx_info *mlx_info)
{
	mlx_info->map_info->ver_angle -= ROLL_STEP;
}

void	rotate_pitch(t_mlx_info *mlx_info)
{
	mlx_info->map_info->ver_angle += ROLL_STEP;
}
