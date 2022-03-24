/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_drawline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:35:23 by hseong            #+#    #+#             */
/*   Updated: 2022/03/24 21:37:54 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//static void	drawline_low(t_img_elem *img_elem, t_point p0, t_point p1);
//static void	drawline_high(t_img_elem *img_elem, t_point p0, t_point p1);
static void	fast_drawline_low(t_img_elem *img_elem, t_point p0, t_point p1);
static void	fast_drawline_high(t_img_elem *img_elem, t_point p0, t_point p1);

void	fdf_drawline(t_img_elem *img_elem, t_point *p0, t_point *p1)
{
	int		dx;
	int		dy;

	dx = ft_abs(p1->x - p0->x);
	dy = ft_abs(p1->y - p0->y);
	if (p0->x > p1->x)
		swap_point(&p0, &p1);
	if (dx > dy)
		fast_drawline_low(img_elem, *p0, *p1);
	else
		fast_drawline_high(img_elem, *p0, *p1);
}

void	fast_drawline_low(t_img_elem *img_elem, t_point p0, t_point p1)
{
	int		dx;
	int		dy;
	int		sy;
	int		diff;

	dx = p1.x - p0.x;
	sy = 1;
	if (p1.y - p0.y < 0)
		sy = -1;
	dy = ft_abs(p1.y - p0.y);
	diff = 2 * dy - dx;
	while (p0.x < p1.x)
	{
		if (p0.x < SCREEN_WIDTH && p0.x >= 0
			&& p0.y >= 0 && p0.y < SCREEN_HEIGHT)
			img_elem->img_arr[p0.x + img_elem->hor_size * p0.y] = p0.color;
		if (diff > 0)
		{
			diff -= dx;
			p0.y += sy;
		}
		diff += dy;
		++p0.x;
	}
}

void	fast_drawline_high(t_img_elem *img_elem, t_point p0, t_point p1)
{
	int		dx;
	int		dy;
	int		sy;
	int		diff;

	dx = p1.x - p0.x;
	sy = 1;
	if (p1.y - p0.y < 0)
		sy = -1;
	dy = abs(p1.y - p0.y);
	diff = 2 * dx - dy;
	while (p0.y != p1.y)
	{
		if (p0.x < SCREEN_WIDTH && p0.x > 0
			&& p0.y > 0 && p0.y < SCREEN_HEIGHT)
			img_elem->img_arr[p0.x + img_elem->hor_size * p0.y] = p0.color;
		if (diff > 0)
		{
			diff -= dy;
			++p0.x;
		}
		diff += dx;
		p0.y += sy;
	}
}

/*
static void	drawline_low(t_img_elem *img_elem, t_point p0, t_point p1)
{
	int		dx;
	int		dy;
	double	diff;
	double	x0 = p0.x;
	double	y0 = p0.y;
	double	x1 = p1.x;
	double	y1 = p1.y;

	dx = x1 - x0;
	dy = y1 - y0;
	diff = (double)dy / dx;
	while (x0 < x1)
	{
		if ((int)x0 < SCREEN_WIDTH && x0 > 0
			&& y0 > 0 && (int)y0 < SCREEN_HEIGHT)
			img_elem->img_arr[(int)(ceil(x0) + img_elem->hor_size * (int)y0)] = p0.color;
		x0 += 1;
		y0 += diff;
	}
}

static void	drawline_high(t_img_elem *img_elem, t_point p0, t_point p1)
{
	int		dx;
	int		dy;
	double	diff;
	double	x0 = p0.x;
	double	y0 = p0.y;
	double	x1 = p1.x;
	double	y1 = p1.y;
	double	temp;

	if (y0 > y1)
	{
		temp = x0;
		x0 = x1;
		x1 = temp;
		temp = y0;
		y0 = y1;
		y1 = temp;
	}
	dx = x1 - x0;
	dy = y1 - y0;
	diff = (double)dx / dy;
	while (y0 < y1)
	{
		if (x0 < SCREEN_WIDTH && x0 > 0
			&& y0 > 0 && y0 < SCREEN_HEIGHT)
			img_elem->img_arr[(int)(ceil(x0) + img_elem->hor_size * (int)y0)] = p0.color;
		y0 += 1;
		x0 += diff;
	}
}
*/
