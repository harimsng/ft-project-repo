/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:05:10 by hseong            #+#    #+#             */
/*   Updated: 2021/10/16 22:42:33 by hseong           ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*ret;

	ret = dest;
	if (dest == 0 || src == 0)
		return (ret);
	while (*dest != 0)
		++dest;
	while (*src != 0)
	{
		*dest = *src;
		++dest;
		++src;
	}
	*dest = 0;
	return (ret);
}
