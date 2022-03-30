/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keymap_rotate2_mac.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:33:17 by hseong            #+#    #+#             */
/*   Updated: 2022/03/30 19:58:22 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_keymap.h"

void	rotate_roll(t_mlx_info *mlx_info)
{
	if (mlx_info->map_info->projection == 0)
		mlx_info->map_info->gamma += PITCH_STEP;
}

void	rotate_rroll(t_mlx_info *mlx_info)
{
	if (mlx_info->map_info->projection == 0)
		mlx_info->map_info->gamma -= PITCH_STEP;
}
