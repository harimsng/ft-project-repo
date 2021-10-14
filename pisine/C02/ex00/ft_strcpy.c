/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:04:11 by hseong            #+#    #+#             */
/*   Updated: 2021/10/14 10:13:35 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// original strcpy doesn't handle the case where dest is null pointerr,
// if executed, segmentation fault occurs.
char	*ft_strcpy(char *dest, char *src)
{
	char	*ret;

	ret = dest;
	while (*src != '\0')
	{
		*dest = *src;
		++dest;
		++src;
	}
	*dest = '\0';
	return (ret);
}
