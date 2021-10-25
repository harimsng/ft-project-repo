/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:56:44 by hseong            #+#    #+#             */
/*   Updated: 2021/10/25 17:56:45 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int			ret;
	int			idx;

	ret = 0;
	idx = 0;
	while (idx < length)
		ret += f(tab[idx++]);
	return (ret);
}
