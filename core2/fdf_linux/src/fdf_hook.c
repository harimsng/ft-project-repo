/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:42:44 by hseong            #+#    #+#             */
/*   Updated: 2022/04/15 01:35:22 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "fdf_keymap.h"

typedef void			(*t_key_func)(t_mlx_info *mlx_info);

int	key_hook(int keycode, void *param)
{
	keycode &= 0xFF;
	if (keycode > 127)
		return (0);
	g_keycode_table[keycode](param);
	return (0);
}

void	fdf_mouse_get_pos(t_mlx_info *mlx_info, int *x, int *y)
{
#ifdef SYS_MAC
	mlx_mouse_get_pos(mlx_info->win_ptr, x, y);
	*x -= g_screen_hwidth;
	*y -= g_screen_hheight;
	mlx_mouse_move(mlx_info->win_ptr, 40, 40);
#else
	mlx_mouse_get_pos(mlx_info->mlx_ptr, mlx_info->win_ptr, x, y);
	*x -= 40;//g_screen_hwidth;
	*y -= 40;//g_screen_hheight;
	mlx_mouse_move(mlx_info->mlx_ptr, mlx_info->win_ptr,
			40, 40);
			//g_screen_hwidth, g_screen_hheight);
#endif
}

void	dummy_func(t_mlx_info *mlx_info)
{
	(void)mlx_info;
}

void	exit_program(t_mlx_info *mlx_info)
{
	fdf_exit(0, mlx_info);
}
