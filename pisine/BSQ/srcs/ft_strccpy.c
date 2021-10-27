/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 03:04:55 by hseong            #+#    #+#             */
/*   Updated: 2021/10/28 03:04:56 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strccpy(unsigned char *dest, unsigned char *src, int width)
{
	int		idx;

	idx = 0;
	while (idx < width)
	{
		dest[idx] = src[idx];
		++idx;
	}
}
