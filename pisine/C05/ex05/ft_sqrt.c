/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:33:58 by hseong            #+#    #+#             */
/*   Updated: 2021/10/13 23:53:52 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	left;
	int	right;
	int	mid;

	if (nb < 1)
		return (0);
	left = 1;
	right = 46340;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (nb > mid * mid)
			left = mid + 1;
		else
			right = mid;
	}
	return (left * left == nb);
}
