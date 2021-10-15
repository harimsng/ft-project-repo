/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:05:10 by hseong            #+#    #+#             */
/*   Updated: 2021/10/15 19:42:26 by harimseong       ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*ret;

	if (dest == NULL || src == NULL)
		return NULL;
	ret = dest;
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
