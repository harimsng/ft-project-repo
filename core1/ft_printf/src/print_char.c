/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:32:33 by hseong            #+#    #+#             */
/*   Updated: 2021/12/08 15:57:27 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list arg, void *buf)
{
	char	*str;

	str = buf;
	*str++ = (char)(va_arg(arg, int));
	*str = 0;
	return (0);
}
