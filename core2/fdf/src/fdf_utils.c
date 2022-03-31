/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:12:02 by hseong            #+#    #+#             */
/*   Updated: 2022/03/31 22:03:55 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
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

void	fdf_debug(t_mlx_info *mlx_info)
{
	char	*debug_str;

	debug_str = mlx_info->map_info->carry;
	if (debug_str != NULL)
		mlx_string_put(mlx_info->mlx_ptr, mlx_info->win_ptr, 0,
			TEXT_HEIGHT * 2 + 2, 0xFFFFFF, mlx_info->map_info->carry);
}

void	get_frametime(t_mlx_info *mlx_info)
{
	static int		frame;
	static clock_t	past;
	static clock_t	now;
	float			frametime;
	char			buf[201];
	int				buf_pos;
	t_map_info		*map_info;

	map_info = mlx_info->map_info;
	now = clock();
	frametime = (float)(now - past) / CLOCKS_PER_SEC;
	past = now;
	buf_pos = snprintf(buf, 200, "fps = %6.2f  frametime = %6.4f  \
alpha = %6.2fdeg  beta = %6.2lfdeg   gamma = %6.2lfdeg",
		1 / frametime, frametime,
		map_info->hor_angle * 180.0 / M_PI,
		map_info->ver_angle * 180.0 / M_PI,
		map_info->gamma * 180.0 / M_PI);
	buf[buf_pos++] = 0;
	snprintf(buf + buf_pos, 200 - buf_pos,
			"x = %5d  y = %5d  dx=%4.2lf  dy=%4.2lf",
			map_info->x0 - g_screen_hwidth,
			map_info->y0 - g_screen_hheight,
			map_info->hor_scale, map_info->ver_scale);
	mlx_string_put(mlx_info->mlx_ptr, mlx_info->win_ptr,
			0, TEXT_HEIGHT, 0xFFFFFF, buf);
	mlx_string_put(mlx_info->mlx_ptr, mlx_info->win_ptr,
			0, 2 * TEXT_HEIGHT + 4, 0xFFFFFF, buf + buf_pos);
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
