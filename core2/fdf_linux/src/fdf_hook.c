/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:42:44 by hseong            #+#    #+#             */
/*   Updated: 2022/04/03 19:52:34 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "fdf_keymap.h"
# include <stdio.h>

int	key_hook(int keycode, void *param)
{
#ifndef SYS_MAC
	if (keycode >= 0xFF && keycode < 0xFF00)
		return (0);
#endif
	keycode &= 0xFF;
	g_keycode_table[keycode](param);
	return (0);
}
//	printf("keycode: %d\n", keycode);

void	dummy_func(t_mlx_info *mlx_info)
{
	(void)mlx_info;
}

void	exit_program(t_mlx_info *mlx_info)
{
	(void)mlx_info;
	exit(0);
}
