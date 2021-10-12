/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:03:46 by hseong            #+#    #+#             */
/*   Updated: 2021/10/12 11:10:08 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b);

void	ft_rev_int_tab(int *tab, int size)
{
	int		*back;

	back = tab + size - 1;
	while (tab < back)
	{
		ft_swap(tab, back);
		++tab;
		--back;
	}
}

void	ft_swap(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
