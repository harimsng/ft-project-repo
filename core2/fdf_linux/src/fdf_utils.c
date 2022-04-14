/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:12:02 by hseong            #+#    #+#             */
/*   Updated: 2022/04/13 15:11:44 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fdf.h"
#include <math.h>
#include <stdlib.h>

double	fdf_modf(double num)
{
	return (num - floor(num));
}

void	swap_point(t_vertex **p0, t_vertex **p1)
{
	t_vertex	*temp;

	temp = *p0;
	*p0 = *p1;
	*p1 = temp;
}

double	get_z_coord(char *s)
{
	static double	max_z;
	double			z;

	if (s == NULL)
		return (max_z);
	z = (double)strtold(s, NULL);
	if (z > max_z)
		max_z = z;
	return (z);
}
