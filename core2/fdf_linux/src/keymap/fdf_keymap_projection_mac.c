/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keymap_projection_mac.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:18:12 by hseong            #+#    #+#             */
/*   Updated: 2022/03/30 17:26:34 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_keymap.h"

void	project_isometric(t_mlx_info *mlx_info)
{
	mlx_info->map_info->projection = 0;
}

void	project_perspective(t_mlx_info *mlx_info)
{
	mlx_info->map_info->projection = 1;
}
