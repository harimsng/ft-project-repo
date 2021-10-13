/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:36:00 by hseong            #+#    #+#             */
/*   Updated: 2021/10/13 23:57:17 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	recur(int nb);

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	return (recur(nb));
}

int	recur(int nb)
{
	int		num;
	int		max;

	num = 3;
	max = 36341;
	if (nb < 46341)
		max = nb;
	while (num < max)
	{
		if (nb % num == 0)
		{
			nb = recur(nb + 1);
			break ;
		}
		++num;
	}
	return (nb);
}
