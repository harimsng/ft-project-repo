/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 03:04:57 by hseong            #+#    #+#             */
/*   Updated: 2021/10/28 03:04:57 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcheck(unsigned char *str, int size)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != '\n' && len < size)
		++len;
	if ((str[len] && str[len] != '\n') || len != size)
		return (1);
	return (0);
}
