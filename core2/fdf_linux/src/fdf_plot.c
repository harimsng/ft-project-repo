/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_plot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:49:08 by hseong            #+#    #+#             */
/*   Updated: 2022/04/13 11:53:00 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_complex.h"
#include <math.h>
#include <pthread.h>

typedef struct s_fractal
{
	double		y;
	t_mlx_info	*mlx_info;
}		t_fractal;

t_uint32	fdf_fractal(double x, double y, t_map_info *map_info);
static void		*fractal_wrapper(void *arg);

static t_mlx_info	*g_mlx_info;

void	fdf_plot_loop(t_mlx_info *mlx_info)
{
	//static int	frame;
	//t_pixel		*img_buf;
	//size_t		hor_px;
	//int			x;
	int			y;
	static int	y_arr[SCREEN_HEIGHT];
//	t_map_info	*map_info;

	//hor_px = mlx_info->img_elem->hor_px;
	//img_buf = mlx_info->img_elem->img_buf;
//	map_info = mlx_info->map_info;
	g_mlx_info = mlx_info;
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
	//	x = 0;
		y_arr[y] = y;
		pthread_create(mlx_info->thread + y, NULL, fractal_wrapper, y_arr + y);
		/*
		while (x < SCREEN_WIDTH)
		{
			pthread_create(
			img_buf[x + y * hor_px] =
//			fdf_fractal((double)(x - map_info->var_x - g_screen_hwidth) / g_screen_hwidth,
//			(double)(y - map_info->var_y - g_screen_hheight) / g_screen_hheight, map_info);
//			fdf_plot(x, y, 1.0, img_elem);
//			fdf_plot(x, y,
//				(pow(x - SCREEN_WIDTH / 2, 2) + pow(y - SCREEN_HEIGHT / 2, 2))
//				/ ((pow(g_screen_hwidth, 2) + pow(g_screen_hheight, 2))),
//				img_elem);
			++x;
		}
		*/
		++y;
	}
	//++frame;
}
/*
void	fdf_plot(int x, int y, double brightness, t_img_elem *img_elem)
{
	img_elem->img_buf[x + y * img_elem->hor_px]
		= 0x081010 + ((int)(0x44 * brightness));
}
*/
void	*fractal_wrapper(void *arg)
{
	t_map_info	*map_info = g_mlx_info->map_info;
	t_pixel		*img_buf = g_mlx_info->img_elem->img_buf;
	int		y = *(int *)arg;
	int		x = 0;
	size_t	hor_px = g_mlx_info->img_elem->hor_px;

	while (x < SCREEN_WIDTH)
	{
		img_buf[x + y * hor_px] =
		fdf_fractal((double)(x - map_info->var_x - g_screen_hwidth) / g_screen_hwidth,
		(double)(y - map_info->var_y - g_screen_hheight) / g_screen_hheight, map_info);
		++x;
	}
	return (NULL);
}
