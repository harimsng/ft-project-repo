/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:12:02 by hseong            #+#    #+#             */
/*   Updated: 2022/03/30 12:43:20 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
# include <time.h>
# include <stdio.h>

double	fdf_modf(double num)
{
	return (num - floor(num));
}

void	swap_point(t_vertex **p0, t_vertex **p1)
{
	t_vertex	*temp;

	temp = *p0;
	*p0 = *p1;
	*p1 = temp;
}

void	get_frametime(t_mlx_info *mlx_info)
{
	static int		frame;
	static clock_t	past;
	static clock_t	now;
	float			frametime;
	float			fps;
	char			buf[201];
	int				buf_pos;

	now = clock();
	frametime = (float)(now - past) / CLOCKS_PER_SEC;
	fps = (float)CLOCKS_PER_SEC / (now - past);
	past = now;
//	if (frame % 20 == 0)
	buf_pos = snprintf(buf, 200, "fps = %6.2f  frametime = %6.4f  alpha = %6.2fdeg  beta = %6.2lfdeg   gamma = %6.2lfdeg", fps, frametime,
	mlx_info->map_info->hor_angle * 180.0 / M_PI, mlx_info->map_info->ver_angle * 180.0 / M_PI, mlx_info->map_info->gamma * 180.0 / M_PI);
	buf[buf_pos] = 0;
	mlx_string_put(mlx_info->mlx_ptr, mlx_info->win_ptr, 0, 16, 0xFFFFFF, buf);
//	printf("fps = %10.2f\t frametime = %10.4f\n", fps, frametime);
	++frame;
}

double	get_z_coord(char *s)
{
	static double	max_z;
	double			z;

	if (s == NULL)
		return (max_z);
	z = (double)ft_atoi(s);
	if (z > max_z)
		max_z = z;
	return (z);
}
