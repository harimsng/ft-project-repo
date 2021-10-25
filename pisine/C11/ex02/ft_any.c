/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:50:36 by hseong            #+#    #+#             */
/*   Updated: 2021/10/25 17:50:37 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ft_str_is_alpha, numeric, lowercase, uppercase ...
// int ft_str_is_something(char *str);
int	ft_any(char **tab, int (*f)(char *))
{
	while (*tab)
	{
		if (f(*tab) != 0)
			return (1);
		++tab;
	}
	return (0);
}
