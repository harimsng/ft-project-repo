/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:36:15 by hseong            #+#    #+#             */
/*   Updated: 2021/10/17 10:36:47 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	ret;

	ret = 0;
	if (src == 0)
		return (ret);
	while (src[ret] != 0)
		++ret;
	if (size == 0 || dest == 0)
		return (ret);
	while (size > 1 && *src != 0)
	{
		*dest = *src;
		++dest;
		++src;
		--size;
	}
	*dest = 0;
	return (ret);
}
