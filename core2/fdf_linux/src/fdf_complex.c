/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_complex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:48:26 by hseong            #+#    #+#             */
/*   Updated: 2022/04/13 12:54:48 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_complex.h"
#include <math.h>

inline void	fdf_complex(t_complex *var, double x, double y)
{
	var->r = x;
	var->i = y;
}

inline t_uint32	fdf_complex_abs(t_complex *var)
{
	return (var->r * var->r + var->i * var->i);
}

inline void	fdf_complex_mul(t_complex *to, t_complex *with)
{
	double	temp_r;

	temp_r = to->r * with->r - to->i * with->i;
	to->i = to->r * with->i + with->r * to->i;
	to->r = temp_r;
}

inline t_uint32	fdf_fractal(double x, double y, t_map_info *map_info)
{
	t_complex			z;
	static const int	rad_2 = FRACT_RADIUS * FRACT_RADIUS;
	t_uint32			count;
	double				temp;

	count = 0;
	x /= map_info->fract_scale;
	y /= map_info->fract_scale;
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
	//count = ((double)count / FRACT_MAXITER)* 0xFF;
	//return (((count) << 16) + (count << 8) + count);
	return (count);
}
