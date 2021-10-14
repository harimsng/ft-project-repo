/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowercase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:04:49 by hseong            #+#    #+#             */
/*   Updated: 2021/10/14 10:23:59 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowercase(char *str)
{
	char	*ret;

	if (str == 0)
		return (0);
	ret = str;
	while (*str != 0)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		++str;
	}
	return (ret);
}
