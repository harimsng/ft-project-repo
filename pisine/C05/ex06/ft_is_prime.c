/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:33:53 by hseong            #+#    #+#             */
/*   Updated: 2021/10/19 09:27:27 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	recur_is_prime(int nb, int num);

int	ft_is_prime(int nb)
{
	if (nb == 2)
		return (1);
	if (nb <= 1 || nb % 2 == 0)
		return (0);
	return (recur_is_prime(nb, 3));
}

int	recur_is_prime(int nb, int num)
{
	if (num > 46340)
		return (1);
	else if (num * num > nb)
		return (1);
	else if (nb % num == 0)
		return (0);
	return (recur_is_prime(nb, num + 2));
}
