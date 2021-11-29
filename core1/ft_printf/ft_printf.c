/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:40:01 by hseong            #+#    #+#             */
/*   Updated: 2021/11/29 21:08:08 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_process(const char **format, va_list arg);

static const t_formats	format_func[9] =
{
	p_char, p_string, p_pointer, p_decimal, p_integer,
	p_unsigned, p_lowhex, p_uphex, p_percent
};

// ordinary characters				: a, b, c, 1, 2, 3, ...	
// conversion specifications		: %s, %c, %d ...
int	ft_printf(const char *format, ...)
{
	va_list		arg;
	
	va_start(arg, format);
	while (*format && format_process(&format, arg))
		++format;
	va_end(arg);
	return (format_process(format));
}

static int	format_process(const char **format, va_list arg)
{
	char		idx;

	if (**format == '%')
	{
		idx = *(++*format);
		idx = (idx == 'c') * 1 + (idx == 's') * 2 + (idx == 'p') * 3
			+ (idx == 'd') * 4 + (idx == 'i') * 4 + (idx == 'u') * 5
			+ (idx == 'x') * 6 + (idx == 'X') * 7 + (idx == '%') * 8;
		format_func[idx]();
	}
	else
		write(1, *format, 1);
}

/*
99		115		112		100		105		117		120		88		37

mod 9
0		7		4		1		6		9		3		7		1

100		116		113		101		106		118		121		89		38
+1 mod 9
1		8		5		2		6		1		4		7		2

mod 10
9		5		2		0		5		7		0		8		7

mod 11
0		5		2		1		6		7		10		0		4

100		116		113		101		106		118		121		89		38
+1 mod 11
1		6		3		2		7		8		0		1		5

mod 12
3		7		4		4		9		9

mod 13
*/
