/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_drawline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:35:23 by hseong            #+#    #+#             */
/*   Updated: 2022/03/27 18:12:46 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fast_drawline_low_up(t_img_elem *img_elem, t_vertex p0, t_vertex p1);
static void	fast_drawline_low_down(t_img_elem *img_elem, t_vertex p0, t_vertex p1);
static void	fast_drawline_high_up(t_img_elem *img_elem, t_vertex p0, t_vertex p1);
static void	fast_drawline_high_down(t_img_elem *img_elem, t_vertex p0, t_vertex p1);

void	fdf_drawline(t_img_elem *img_elem, t_vertex *p0, t_vertex *p1)
{
	int		dx;
	int		dy;

	dx = p1->x - p0->x;
	dy = p1->y - p0->y;
	if (dx < 0)
		swap_point(&p0, &p1);
	if (ft_abs(dx) > ft_abs(dy))
	{
		if (dy > 0)
			fast_drawline_low_up(img_elem, *p0, *p1);
		else
			fast_drawline_low_down(img_elem, *p0, *p1);
	}
	else
	{
		if (dy > 0)
			fast_drawline_high_up(img_elem, *p0, *p1);
		else
			fast_drawline_high_down(img_elem, *p0, *p1);
	}
}

static void	fast_drawline_low_down(t_img_elem *img_elem, t_vertex p0, t_vertex p1)
{
	int		dx;
	int		dy;
	int		diff;
	int		x0;
	int		y0;

	x0 = p0.x;
	y0 = p0.y;
	dx = (int)p1.x - x0;
	dy = ft_abs((int)p1.y - y0);
	diff = 2 * dy - dx;
	while (x0 <= (int)p1.x && (t_uint32)y0 < SCREEN_HEIGHT)
	{
		img_elem->img_arr[x0 + img_elem->hor_size * y0] =
			grade_color(p0.color, p1.color, (x0 - (int)p0.x) / (p1.x - p0.x));
		if (diff > 0)
		{
			diff -= dx;
			--y0;
		}
		diff += dy;
		++x0;
	}
}
static void	fast_drawline_high_down(t_img_elem *img_elem, t_vertex p0, t_vertex p1)
{
	int		dx;
	int		dy;
	int		diff;
	int		x0;
	int		y0;

	x0 = p0.x;
	y0 = p0.y;
	dx = (int)p1.x - x0;
	dy = ft_abs((int)p1.y - y0);
	diff = 2 * dx - dy;
	while (y0 >= (int)p1.y && (t_uint32)x0 < SCREEN_WIDTH)
	{
		img_elem->img_arr[x0 + img_elem->hor_size * y0] =
			grade_color(p0.color, p1.color, (y0 - (int)p0.y) / (p1.y - p0.y));
		if (diff > 0)
		{
			diff -= dy;
			++x0;
		}
		diff += dx;
		--y0;
	}
}

static void	fast_drawline_low_up(t_img_elem *img_elem, t_vertex p0, t_vertex p1)
{
	int		dx;
	int		dy;
	int		diff;
	int		x0;
	int		y0;

	x0 = p0.x;
	y0 = p0.y;
	dx = (int)p1.x - x0;
	dy = ft_abs((int)p1.y - y0);
	diff = 2 * dy - dx;
	while (x0 <= (int)p1.x && (t_uint32)y0 < SCREEN_HEIGHT)
	{
		img_elem->img_arr[x0 + img_elem->hor_size * y0] =
			grade_color(p0.color, p1.color, (x0 - (int)p0.x) / (p1.x - p0.x));
		if (diff > 0)
		{
			diff -= dx;
			++y0;
		}
		diff += dy;
		++x0;
	}
}
static void	fast_drawline_high_up(t_img_elem *img_elem, t_vertex p0, t_vertex p1)
{
	int		dx;
	int		dy;
	int		diff;
	int		x0;
	int		y0;

	x0 = p0.x;
	y0 = p0.y;
	dx = ((int)p1.x - x0);
	dy = ft_abs((int)p1.y - y0);
	diff = 2 * dx - dy;
	while (y0 <= (int)p1.y && (t_uint32)x0 < SCREEN_WIDTH)
	{
		img_elem->img_arr[x0 + img_elem->hor_size * y0] =
			grade_color(p0.color, p1.color, (y0 - (int)p0.y) / (p1.y - p0.y));
		if (diff > 0)
		{
			diff -= dy;
			++x0;
		}
		diff += dx;
		++y0;
	}
}

/*
integer point drawline

void	fast_drawline_low(t_img_elem *img_elem, t_vertex p0, t_vertex p1)
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
	dy *= 2;
	diff = 2 * dy - dx;
	dx *= 2;
	while (p0.x < p1.x)
	{
		if (p0.x < SCREEN_WIDTH && p0.x >= 0
			&& p0.y >= 0 && p0.y < SCREEN_HEIGHT)
			img_elem->img_arr[lround(p0.x + img_elem->hor_size * p0.y)] = p0.color;
		if (diff > 0)
		{
			diff -= dx;
			p0.y += sy;
		}
		diff += dy;
		++p0.x;
	}
}

void	fast_drawline_high(t_img_elem *img_elem, t_vertex p0, t_vertex p1)
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
	dx *= 2;
	diff = 2 * dx - dy;
	dy *= 2;
	while (p0.y != p1.y)
	{
		if (p0.x < SCREEN_WIDTH && p0.x > 0
			&& p0.y > 0 && p0.y < SCREEN_HEIGHT)
			img_elem->img_arr[lround(p0.x + img_elem->hor_size * p0.y)] = p0.color;
		if (diff > 0)
		{
			diff -= dy;
			++p0.x;
		}
		diff += dx;
		p0.y += sy;
	}
}
*/
