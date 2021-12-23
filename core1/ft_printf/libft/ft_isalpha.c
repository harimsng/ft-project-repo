/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 21:06:58 by hseong            #+#    #+#             */
/*   Updated: 2021/11/10 18:27:07 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// result doesn't match the standard function.
int	ft_isalpha(int c)
{
	if ((c > 64 && c < 91)
		|| (c > 96 && c < 123))
		return (1);
	return (0);
}