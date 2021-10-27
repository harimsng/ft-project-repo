/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:58:50 by hseong            #+#    #+#             */
/*   Updated: 2021/10/27 23:31:45 by hseong           ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

// descending or ascending
int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int			idx;
	int			order;

	if (length < 3)
		return (1);
	order = 1 + (-2) * (tab[0] > tab[1]);
	idx = 0;
	while (idx < length - 1)
	{
		if (order * f(tab[idx], tab[idx + 1]) > 0)
			return (0);
		++idx;
	}
	return (1);
}
