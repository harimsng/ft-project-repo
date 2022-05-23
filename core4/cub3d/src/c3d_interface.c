/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_interface.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:13:45 by hseong            #+#    #+#             */
/*   Updated: 2022/05/24 05:07:46 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "c3d.h"
#include <math.h>
#include <time.h>
#include <stdio.h>

void	get_frametime(t_mlx_info *mlx_info)
{
	static int		frame;
	static clock_t	past;
	static clock_t	now;
	float			frametime;
	char			buf[100];

	now = clock();
	frametime = (float)(now - past) / CLOCKS_PER_SEC;
	past = now;
	snprintf(buf, 100, "fps = %6.2f  frametime = %6.4f",
		1 / frametime, frametime);
	mlx_string_put(mlx_info->mlx_ptr, mlx_info->win_ptr,
		0, TEXT_HEIGHT, 0xFFFFFF, buf);
	++frame;
}
