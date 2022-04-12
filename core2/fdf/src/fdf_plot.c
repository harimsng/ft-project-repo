/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_plot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:49:08 by hseong            #+#    #+#             */
/*   Updated: 2022/04/13 00:45:42 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_complex.h"
#include <math.h>

static t_uint32	fdf_fractal(double x, double y, t_map_info *map_info);

void	fdf_plot_loop(t_mlx_info *mlx_info)
{
	static int	frame;
	t_pixel		*img_buf;
	size_t		hor_px;
	int			x;
	int			y;
	t_map_info	*map_info;

	hor_px = mlx_info->img_elem->hor_px;
	img_buf = mlx_info->img_elem->img_buf;
	map_info = mlx_info->map_info;
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			img_buf[x + y * hor_px] =
			fdf_fractal((double)(x - map_info->var_x - g_screen_hwidth) / g_screen_hwidth,
			(double)(y - map_info->var_y - g_screen_hheight) / g_screen_hheight, map_info);
//			fdf_plot(x, y, 1.0, img_elem);
//			fdf_plot(x, y,
//				(pow(x - SCREEN_WIDTH / 2, 2) + pow(y - SCREEN_HEIGHT / 2, 2))
//				/ ((pow(g_screen_hwidth, 2) + pow(g_screen_hheight, 2))),
//				img_elem);
			++x;
		}
		++y;
	}
	++frame;
}
/*
void	fdf_plot(int x, int y, double brightness, t_img_elem *img_elem)
{
	img_elem->img_buf[x + y * img_elem->hor_px]
		= 0x081010 + ((int)(0x44 * brightness));
}
*/

inline t_uint32	fdf_fractal(double x, double y, t_map_info *map_info)
{
	t_complex			z;
	static const int	rad_2 = FRACT_RADIUS * FRACT_RADIUS;
	int					count;
	double				temp;

	count = 0;
	x *= FRACT_SCALE / map_info->hor_scale;
	y *= FRACT_SCALE / map_info->hor_scale * 0.8;
	z.r = x;
	z.i = y;

	// f(z) = z^2 + c;
	// 		= (x + iy) * (x + iy) + c
	// 		= x^2 - y^2 + 2 * i*x*y + c
	while (z.r * z.r + z.i * z.i < rad_2 && count < FRACT_MAXITER)
	{
		temp = z.r * z.r - z.i * z.i;
		z.i = 2 * z.r * z.i + FRACT_CONST_I;
		z.r = temp + FRACT_CONST_R;
		++count;
	}
	count = ((double)count / FRACT_MAXITER)* 0xFF;
	return (((count) << 16) + (count << 8) + count);
}
