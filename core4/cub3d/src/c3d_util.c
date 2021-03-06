/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 00:27:22 by hseong            #+#    #+#             */
/*   Updated: 2022/05/18 20:18:17 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"
#include <math.h>

double	vec2_dist(t_vec2 *p0, t_vec2 *p1)
{
	double	x;
	double	y;

	x = p0->x - p1->x;
	y = p0->y - p1->y;
	return (sqrt(x * x + y * y));
}

void	swap_point(t_vec4 **p0, t_vec4 **p1)
{
	t_vec4	*temp;

	temp = *p0;
	*p0 = *p1;
	*p1 = temp;
}
