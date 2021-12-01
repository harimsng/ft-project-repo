/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:40:01 by hseong            #+#    #+#             */
/*   Updated: 2021/12/01 17:52:40 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_process(const char **format, va_list arg);

// ordinary characters				: a, b, c, 1, 2, 3, ...	
// conversion specifications		: %s, %c, %d ...
int	ft_printf(const char *format, ...)
{
	va_list		arg;
	int			ret;
	
	ret = 0;
	va_start(arg, format);
	while (*format && ret >= 0)
	{
		ret += format_process(&format, arg);
		++format;
	}
	va_end(arg);
	return (ret);
}

static int	format_process(const char **format, va_list arg)
{
	int				idx;

	if (**format == '%')
	{
		++*format;
		idx = 0;
		while (idx < MAX_FORMAT && g_format_tab[idx] != **format)
			++idx;
		if (idx == MAX_FORMAT)
			return (INT_MIN);
		return (g_format_func[idx](arg));
	}
	return (write(1, *format, 1));
}
