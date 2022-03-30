/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keymap_scale_mac.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:21:17 by hseong            #+#    #+#             */
/*   Updated: 2022/03/30 21:18:11 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_keymap.h"
#include "fdf_const.h"

void	fdf_setup_map(t_map_info *map_info);

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
	int		temp;

	temp = mlx_info->map_info->projection;
	fdf_setup_map(mlx_info->map_info);
	mlx_info->map_info->projection = temp;
}

void	automove_map(t_mlx_info *mlx_info)
{
	mlx_info->map_info->automove_flag ^= TRUE;
}

void	turn_interface(t_mlx_info *mlx_info)
{
	mlx_info->map_info->interface_flag ^= TRUE;
}
