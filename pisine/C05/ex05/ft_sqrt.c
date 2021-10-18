/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:33:58 by hseong            #+#    #+#             */
/*   Updated: 2021/10/18 16:31:44 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	recur_sqrt(int nb, int sqrt);

int	ft_sqrt(int nb)
{
	if (nb <= 0)
		return (0);
	return recur_sqrt(nb, 1);
}

int	recur_sqrt(int nb, int sqrt)
{
//	if (sqrt == 46341)
//		return (0);
	if (sqrt * sqrt > nb)
		return (0);
	else if (sqrt * sqrt == nb)
		return (sqrt);
	return recur_sqrt(nb, sqrt + 1);
}
