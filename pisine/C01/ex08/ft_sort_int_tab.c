/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:03:52 by hseong            #+#    #+#             */
/*   Updated: 2021/10/12 11:10:12 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b);

void	ft_sort_int_tab(int *tab, int size)
{
	int		idx;
	int		jdx;

	idx = 0;
	while (idx < size - 1)
	{
		jdx = idx + 1;
		while (jdx < size)
		{
			if (tab[idx] > tab[jdx])
				ft_swap(tab + idx, tab + jdx);
			++jdx;
		}
		++idx;
	}
}

void	ft_swap(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
