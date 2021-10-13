/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:34:06 by hseong            #+#    #+#             */
/*   Updated: 2021/10/13 22:34:07 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	recur(int nb, int power);

int	ft_recursive_power(int nb, int power)
{
	if (power < 0 || (nb == 0 && power > 0))
		return (0);
	else if (power == 0)
		return (1);
	return (recur(nb, power));
}

int	recur(int nb, int power)
{
	if (power == 0)
		return (1);
	return (nb * recur(nb, power - 1));
}
