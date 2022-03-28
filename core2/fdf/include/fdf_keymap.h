/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keymap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:26:57 by hseong            #+#    #+#             */
/*   Updated: 2022/03/28 17:14:07 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_KEYMAP_H
# define FDF_KEYMAP_H

# include "fdf_type.h"
# include "fdf_const.h"

void	move_obj_left(t_mlx_info *mlx_info);
void	move_obj_right(t_mlx_info *mlx_info);
void	move_obj_up(t_mlx_info *mlx_info);
void	move_obj_down(t_mlx_info *mlx_info);
void	rotate_ccw(t_mlx_info *mlx_info);
void	rotate_cw(t_mlx_info *mlx_info);
void	rotate_roll(t_mlx_info *mlx_info);
void	rotate_rroll(t_mlx_info *mlx_info);
void	scale_up(t_mlx_info *mlx_info);
void	scale_down(t_mlx_info *mlx_info);

#endif
