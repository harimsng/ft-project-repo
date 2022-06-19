#include "mlx.h"
#include <stdint.h>

static void	swap_point(t_vertex *p0, t_vertex *p1);
static void	drawline_low_up(t_img *img, t_vertex p0, t_vertex p1);
static void	drawline_low_down(t_img *img, t_vertex p0, t_vertex p1);
static void	drawline_high_up(t_img *img, t_vertex p0, t_vertex p1);
static void	drawline_high_down(t_img *img, t_vertex p0, t_vertex p1);

void	fdf_drawline(t_img *img, t_vertex *p0, t_vertex *p1)
{
	int		dy;

	if ((int)(p1->x - p0->x) < 0)
		swap_point(&p0, &p1);
	dy = p1->y - p0->y;
	if ((uint32_t)p0->x >= SCREEN_WIDTH || (uint32_t)p0->y >= SCREEN_HEIGHT
		|| (uint32_t)p1->x >= SCREEN_WIDTH || (uint32_t)p1->y >= SCREEN_HEIGHT)
		return ;
	mlx_put_pixel(img, (int)p0->x, (int)p0->y, p0->color);
	if ((int)(p1->x - p0->x) > ft_abs(dy))
	{
		if (dy > 0)
			drawline_low_up(img_elem, *p0, *p1);
		else
			drawline_low_down(img_elem, *p0, *p1);
	}
	else
	{
		if (dy > 0)
			drawline_high_up(img_elem, *p0, *p1);
		else
			drawline_high_down(img_elem, *p0, *p1);
	}
	mlx_put_pixel(img, (int)p1->x, (int)p1->y, p1->color);
}

void	drawline_low_down(t_img *img, t_vertex p0, t_vertex p1)
{
	int		dx;
	int		dy;
	int		diff;
	int		x0;
	int		y0;

	x0 = p0.x;
	y0 = p0.y;
	dx = (int)p1.x - (int)p0.x;
	dy = (int)p0.y - (int)p1.y;
	diff = 2 * dy - dx;
	while (++x0 < (int)p1.x)
	{
		mlx_put_pixel(img, x0, y0, p0->color);
		if (diff > 0)
		{
			diff -= dx;
			--y0;
		}
		diff += dy;
	}
}

void	drawline_high_down(t_img *img, t_vertex p0, t_vertex p1)
{
	int		dx;
	int		dy;
	int		diff;
	int		x0;
	int		y0;

	x0 = p0.x;
	y0 = p0.y;
	dx = (int)p1.x - (int)p0.x;
	dy = (int)p0.y - (int)p1.y;
	diff = 2 * dx - dy;
	while (--y0 > (int)p1.y)
	{
		mlx_put_pixel(img, x0, y0, p0->color);
		if (diff > 0)
		{
			diff -= dy;
			++x0;
		}
		diff += dx;
	}
}

void	drawline_low_up(t_img *img, t_vertex p0, t_vertex p1)
{
	int		dx;
	int		dy;
	int		diff;
	int		x0;
	int		y0;

	x0 = p0.x;
	y0 = p0.y;
	dx = (int)p1.x - (int)p0.x;
	dy = (int)p1.y - (int)p0.y;
	diff = 2 * dy - dx;
	while (++x0 < (int)p1.x)
	{
		mlx_put_pixel(img, x0, y0, p0->color);
		if (diff > 0)
		{
			diff -= dx;
			++y0;
		}
		diff += dy;
	}
}

void	drawline_high_up(t_img *img, t_vertex p0, t_vertex p1)
{
	int		dx;
	int		dy;
	int		diff;
	int		x0;
	int		y0;

	x0 = p0.x;
	y0 = p0.y;
	dx = (int)p1.x - (int)p0.x;
	dy = (int)p1.y - (int)p0.y;
	diff = 2 * dx - dy;
	while (++y0 < (int)p1.y)
	{
		mlx_put_pixel(img, x0, y0, p0->color);
		if (diff > 0)
		{
			diff -= dy;
			++x0;
		}
		diff += dx;
	}
}

void	swap_point(t_vertex *p0, t_vertex *p1)
{
	t_vertex	temp;

	temp = *p0;
	*p0 = *p1;
	*p1 = temp;
}
