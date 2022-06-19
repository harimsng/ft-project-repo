/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:42:44 by hseong            #+#    #+#             */
/*   Updated: 2022/05/24 10:04:24 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "c3d.h"
#include "c3d_keymap.h"

int	key_hook(int keycode, void *param)
{
	keycode &= 0xFF;
	if (keycode > 127)
		return (0);
	g_keycode_table[keycode](param);
	return (0);
}

void	c3d_mouse_get_pos(t_mlx_info *mlx_info, int *x, int *y)
{
#ifdef SYS_MAC
	mlx_mouse_get_pos(mlx_info->win_ptr, x, y);
	*x -= 100;
	*y -= 92;
	mlx_mouse_move(mlx_info->win_ptr, 100, SCREEN_HEIGHT - 50);
#else
	mlx_mouse_get_pos(mlx_info->mlx_ptr, mlx_info->win_ptr, x, y);
	*x -= SCREEN_WIDTH >> 1;//g_screen_hwidth;
	*y -= SCREEN_HEIGHT >> 1;//g_screen_hheight;
	mlx_mouse_move(mlx_info->mlx_ptr, mlx_info->win_ptr,
			SCREEN_WIDTH >> 1, SCREEN_HEIGHT >> 1);
			//g_screen_hwidth, g_screen_hheight);
#endif
}

void	dummy_func(t_mlx_info *mlx_info)
{
	(void)mlx_info;
}

void	exit_program(t_mlx_info *mlx_info)
{
	c3d_exit(0, mlx_info);
}
