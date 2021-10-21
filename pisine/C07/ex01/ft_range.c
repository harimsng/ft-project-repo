/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:10:08 by hseong            #+#    #+#             */
/*   Updated: 2021/10/21 10:10:09 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		*ret;
	int		idx;

	if (min >= max)
		return (0);
	ret = (int *)malloc(sizeof(int) * (max - min));
	idx = 0;
	while (min < max)
	{
		ret[idx] = min;
		++idx;
		++min;
	}
	return (ret);
}
