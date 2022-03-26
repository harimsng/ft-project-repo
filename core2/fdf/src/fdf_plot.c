/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_plot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:49:08 by hseong            #+#    #+#             */
/*   Updated: 2022/03/26 21:11:13 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_update(t_img_elem *img_elem)
{
	static int	frame;
	t_pixel		*img_arr;
	int			x;
	int			y;

	img_arr = img_elem->img_arr;
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			fdf_plot(x, y, 0.99999999, img_elem);
			++x;
		}
		++y;
	}
	++frame;
}

// frame overflow
void	fdf_plot(int x, int y, double color, t_img_elem *img_elem)
{
	img_elem->img_arr[x + y * img_elem->hor_size] = (int)(0xFE * color) * 0x00010101;
}

/*
void	fdf_plot_img(double x, double y, double color, t_point **map)
{
	map[
}
*/
