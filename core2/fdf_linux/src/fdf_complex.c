/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_complex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:48:26 by hseong            #+#    #+#             */
/*   Updated: 2022/04/11 17:02:20 by hseong           ###   ########.fr       */
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
