/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_plot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:49:08 by hseong            #+#    #+#             */
/*   Updated: 2022/03/30 12:28:29 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_update(t_img_elem *img_elem)
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
			fdf_plot(x, y, (double)x / SCREEN_WIDTH, img_elem);
			++x;
		}
		++y;
	}
	++frame;
}

void	fdf_plot(int x, int y, double brightness, t_img_elem *img_elem)
{
	img_elem->img_buf[x + y * img_elem->hor_size]
		= (int)brightness * 0x80 * 0x10000
		+ (int)brightness * 0x40 * 0x100
		+ (int)brightness * 0x20 * 0x1;
}
