/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:27:35 by hseong            #+#    #+#             */
/*   Updated: 2021/10/25 17:32:26 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int		idx;
	int		*ret;

	if (!tab || !f || !length)
		return (0);
	ret = (int *)malloc(sizeof(int) * length);
	idx = 0;
	while (idx < length)
	{
		ret[idx] = f(tab[idx]);
		++idx;
	}
	return (ret);
}
