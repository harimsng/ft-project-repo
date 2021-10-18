/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:36:00 by hseong            #+#    #+#             */
/*   Updated: 2021/10/18 18:31:39 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	recur(int nb);

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	return (recur(nb + (nb % 2 == 0)));
}

// 46341 * 46341 = 2147488281 > INT_MAX
// 46340 * 46340 = 2147395600 < INT_MAX
int	recur(int nb)
{
	int		num;

	num = 3;
	while (num * num <= nb && num < 46341)
	{
		if (nb % num == 0)
		{
			nb = recur(nb + 2);
			break ;
		}
		num += 2;
	}
	return (nb);
}
