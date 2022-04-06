/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:42:44 by hseong            #+#    #+#             */
/*   Updated: 2022/04/07 00:19:20 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_keymap.h"

typedef void			(*t_key_func)(t_mlx_info *mlx_info);

int	key_hook(int keycode, void *param)
{
	if (keycode > 127 || keycode < 0)
		return (0);
	g_keycode_table[keycode](param);
	return (0);
}

void	dummy_func(t_mlx_info *mlx_info)
{
	(void)mlx_info;
}

void	exit_program(t_mlx_info *mlx_info)
{
	fdf_exit(0, mlx_info);
}
