/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:48:22 by hseong            #+#    #+#             */
/*   Updated: 2021/10/19 11:54:46 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int		ret;

	if (nb < 0)
		return (0);
	ret = 1;
	while (nb > 0)
	{
		ret *= nb;
		--nb;
	}
	return (ret);
}
