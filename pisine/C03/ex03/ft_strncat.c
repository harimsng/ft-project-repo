/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:14:49 by hseong            #+#    #+#             */
/*   Updated: 2021/10/11 23:14:52 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	len;
	char			*ret;

	ret = dest;
	while (*dest != 0)
		++dest;
	len = 0;
	while (len < nb && *src != 0)
	{
		*dest = *src;
		++dest;
		++src;
		++len;
	}
	return (ret);
}
