/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keymap_transl2_mac.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:48:40 by hseong            #+#    #+#             */
/*   Updated: 2022/04/01 21:32:03 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_keymap.h"

void move_obj_up(t_mlx_info *mlx_info)
{
	mlx_info->map_info->var_height += HEIGHT_STEP;
}

void move_obj_down(t_mlx_info *mlx_info)
{
	mlx_info->map_info->var_height -= HEIGHT_STEP;
}
