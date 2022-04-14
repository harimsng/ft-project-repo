/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_complex.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:47:16 by hseong            #+#    #+#             */
/*   Updated: 2022/04/13 17:17:05 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_COMPLEX_H
# define FDF_COMPLEX_H

# include "fdf.h"

# define FRACT_RADIUS (2.0)
# define FRACT_SCALE (0.2)
# define FRACT_MAXITER (128)

//# define FRACT_CONST_R (0.285)
//# define FRACT_CONST_I (0.01)

//# define FRACT_CONST_R (-0.7269)
//# define FRACT_CONST_I (0.1889)

//# define FRACT_CONST_R (-0.4)
//# define FRACT_CONST_I (0.6)

# define FRACT_CONST_R (-0.8)
# define FRACT_CONST_I (0.156)

//# define FRACT_CONST_R (-0.835)
//# define FRACT_CONST_I (-0.2321)

//# define FRACT_CONST_R (-0.70176)
//# define FRACT_CONST_I (-0.3842)

# define FRACT_X0 (0.0)
# define FRACT_Y0 (0.0)

typedef struct s_fract
{
	double	radius;
	size_t	maxiter;
}			t_fract;

typedef struct s_complex
{
	double	r;
	double	i;
}			t_complex;

void		fdf_complex(t_complex *var, double x, double y);
t_uint32	fdf_complex_abs(t_complex *var);
void		fdf_complex_mul(t_complex *to, t_complex *with);

#endif
