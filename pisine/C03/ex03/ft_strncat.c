/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:14:49 by hseong            #+#    #+#             */
/*   Updated: 2021/10/17 15:39:56 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	idx;
	char			*ret;

	ret = dest;
	if (dest == (void *)0 || src == (void *)0)
		return (ret);
	while (*dest != 0)
		++dest;
	idx = 0;
	while (idx < nb && *src != 0)
	{
		*dest = *src;
		++dest;
		++src;
		++idx;
	}
	*dest = 0;
	return (ret);
}
