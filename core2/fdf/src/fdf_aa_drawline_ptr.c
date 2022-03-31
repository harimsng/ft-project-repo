/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_aa_drawline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:06:03 by hseong            #+#    #+#             */
/*   Updated: 2022/03/29 18:09:00 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	aa_drawline_low(t_img_elem *img_elem, t_vertex *p0, t_vertex *p1);
static void	aa_drawline_high(t_img_elem *img_elem, t_vertex *p0, t_vertex *p1);

void	fdf_aa_drawline(t_img_elem *img_elem, t_vertex *p0, t_vertex *p1)
{
	int		dx;
	int		dy;

	dx = p1->x - p0->x;
	dy = p1->y - p0->y;
	if ((t_uint32)p0->x >= SCREEN_WIDTH - 1
		|| (t_uint32)p0->y >= SCREEN_HEIGHT - 1
		|| (t_uint32)p1->x >= SCREEN_WIDTH - 1
		|| (t_uint32)p1->y >= SCREEN_HEIGHT - 1)
		return ;
	img_elem->img_arr[(int)p0->x + img_elem->hor_size * (int)p0->y] = p0->color;
	if (ft_abs(dx) > ft_abs(dy))
		aa_drawline_low(img_elem, p0, p1);
	else
	{
		if (dy < 0)
			aa_drawline_high(img_elem, p1, p0);
		else
			aa_drawline_high(img_elem, p0, p1);
	}
	img_elem->img_arr[(int)p1->x + img_elem->hor_size * (int)p1->y] = p1->color;
}

void	aa_drawline_low(t_img_elem *img_elem, t_vertex *p0, t_vertex *p1)
{
	int			idx;
	int			ix0;
	double		y;
	double		dx;
	double		dydx;

	dx = p1->x - p0->x;
	dydx = (p1->y - p0->y) / dx;
	dx = 1 / dx;
	y = p0->y;
	ix0 = p0->x + 1.0;
	while (ix0 < (int)p1->x)
	{
		idx = (int)y * img_elem->hor_size + ix0;
		img_elem->img_arr[idx] = grade_color_aa(p0->color, p1->color,
				(ix0 - p0->x) * dx, 1.0 - fdf_modf(y));
		img_elem->img_arr[idx + img_elem->hor_size] = grade_color_aa(p0->color,
				p1->color, (ix0 - p0->x) * dx, fdf_modf(y));
		y += dydx;
		++ix0;
	}
}

void	aa_drawline_high(t_img_elem *img_elem, t_vertex *p0, t_vertex *p1)
{
	int			idx;
	int			iy0;
	double		x;
	double		dy;
	double		dxdy;

	dy = p1->y - p0->y;
	dxdy = (p1->x - p0->x) / dy;
	dy = 1 / dy;
	iy0 = p0->y + 1.0;
	x = p0->x;
	while (iy0 < (int)p1->y)
	{
		idx = (int)(x) + img_elem->hor_size * iy0;
		img_elem->img_arr[idx] = grade_color_aa(p0->color, p1->color,
				(iy0 - p0->y) * dy, 1.0 - fdf_modf(x));
		img_elem->img_arr[idx + 1] = grade_color_aa(p0->color, p1->color,
				(iy0 - p0->y) * dy, fdf_modf(x));
		x += dxdy;
		++iy0;
	}
}