/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:48:22 by hseong            #+#    #+#             */
/*   Updated: 2021/10/13 20:05:31 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int		ret;
	int		itr;

	if (nb < 0)
		return (0);
	ret = 1;
	itr = 0;
	while (itr < nb)
	{
		ret *= itr + 1;
		++itr;
	}
	return (ret);
}
