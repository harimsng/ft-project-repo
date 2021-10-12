/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:21:20 by hseong            #+#    #+#             */
/*   Updated: 2021/10/12 17:21:22 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	idx;
	unsigned int	ret;

	ret = 0;
	while (src[ret] != 0)
		++ret;
	idx = 0;
	while (idx < size && *dest != 0)
	{
		++idx;
		++ret;
		++dest;
	}
	if (size == 0)
		return (ret);
	while (idx < size - 1 && *src != 0)
	{
		*dest = *src;
		++idx;
		++dest;
		++src;
		*dest = 0;
	}
	return (ret);
}
