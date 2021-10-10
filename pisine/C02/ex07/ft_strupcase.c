/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:04:47 by hseong            #+#    #+#             */
/*   Updated: 2021/10/10 21:04:47 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int		diff;
	char	*ret;

	ret = str;
	diff = 'a' - 'A';
	while (*str != 0)
	{
		if (*str >= 'a' && *str <= 'z')
			*str = *str - diff;
		++str;
	}
	return (ret);
}
