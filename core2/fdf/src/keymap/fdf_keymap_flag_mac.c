/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keymap_flag_mac.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:53:59 by hseong            #+#    #+#             */
/*   Updated: 2022/04/05 13:15:33 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_keymap.h"

void	fdf_setup_map(t_map_info *map_info);

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

void	turn_background(t_mlx_info *mlx_info)
{
	mlx_info->map_info->background_flag ^= TRUE;
}

void	turn_diag(t_mlx_info *mlx_info)
{
	mlx_info->map_info->colored_flag ^= TRUE;
}
