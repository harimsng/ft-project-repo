/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:04:37 by hseong            #+#    #+#             */
/*   Updated: 2021/10/14 10:20:10 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	if (str == 0)
		return (0);
	while (1)
	{
		if (*str == 0)
			return (1);
		else if (*str < 'a' || *str > 'z')
			return (0);
		++str;
	}
	return (1);
}
