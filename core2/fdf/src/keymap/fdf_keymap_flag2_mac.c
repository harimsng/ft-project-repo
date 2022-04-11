/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keymap_flag2_mac.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:08:55 by hseong            #+#    #+#             */
/*   Updated: 2022/04/11 16:25:36 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_keymap.h"

void	turn_wireframe(t_mlx_info *mlx_info)
{
	mlx_info->mlx_flag->wireframe_flag ^= 1;
}
