/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:44:37 by hseong            #+#    #+#             */
/*   Updated: 2021/12/08 15:46:37 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(va_list arg, void *buf)
{
	char	*str;

	str = va_arg(arg, char *);
	if (!str)
		ft_strlcpy(*(char **)buf, "(null)", NUMERIC_BUF_SIZE);
	else
		*(char **)buf = str;
	return (0);
}
