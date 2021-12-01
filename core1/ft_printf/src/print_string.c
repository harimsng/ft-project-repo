/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:44:37 by hseong            #+#    #+#             */
/*   Updated: 2021/12/01 17:55:03 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(va_list arg)
{
	char		*str;

	str = va_arg(arg, char *);
	if (!str)
		return (write(1, "(null)", 6));
	return (ft_putstr_fd(str, 1));
}
