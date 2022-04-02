/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lut_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:09:55 by hseong            #+#    #+#             */
/*   Updated: 2022/03/20 16:15:22 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

int	main(void)
{
	float	lut_sin[360];
	float	lut_cos[360];
	float	lut_tan[360];
	float	lut_atan[360];

	for (int i = 0; i < 360; ++i)
	{
		lut_sin[i] = sin(i / 360);
		lut_cos[i] = sin(i / 360);
		lut_tan[i] = sin(i / 360);
		lut_atan[i] = sin(i / 360);
	}
	printf("%f %f\n", lut_sin[30], sin(30));
}
