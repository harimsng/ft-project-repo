/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:36:15 by hseong            #+#    #+#             */
/*   Updated: 2021/10/10 21:36:16 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	ret;

	if (size == 0)
		return (0);
	ret = 0;
	while (size > 1 && *src != 0)
	{
		*dest = *src;
		++dest;
		++src;
		++ret;
		--size;
	}
	*dest = 0;
	while (*src != 0)
	{
		++ret;
		++src;
	}
	return (ret);
}
