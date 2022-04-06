/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_plot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:49:08 by hseong            #+#    #+#             */
/*   Updated: 2022/04/07 00:26:00 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	fdf_plot_loop(t_img_elem *img_elem)
{
	static int	frame;
	t_pixel		*img_buf;
	int			x;
	int			y;

	img_buf = img_elem->img_buf;
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			fdf_plot(x, y,
				(pow(x - SCREEN_WIDTH / 2, 2) + pow(y - SCREEN_HEIGHT / 2, 2))
				/ ((pow(g_screen_hwidth, 2) + pow(g_screen_hheight, 2))),
				img_elem);
			++x;
		}
		++y;
	}
	++frame;
}

void	fdf_plot(int x, int y, double brightness, t_img_elem *img_elem)
{
	img_elem->img_buf[x + y * img_elem->hor_px]
		= 0x081010 + ((int)(0x44 * brightness));
}
