/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:23:20 by hseong            #+#    #+#             */
/*   Updated: 2021/10/13 20:23:23 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int		ret;

	if (power < 0 || (nb == 0 && power > 0))
		return (0);
	else if (power == 0)
		return (1);
	ret = 1;
	while (power > 0)
	{
		ret *= nb;
		--power;
	}
	return (ret);
}
