/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:40:01 by hseong            #+#    #+#             */
/*   Updated: 2021/12/13 12:27:22 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// format %[flags][width][.precision][length]specifier
// [flags] = '+', ' ', "0x" or "0X" 
// output [padding][sign][integer precision][number][.float precision][-padding]
// string [padding][string precision][padding]

static int			format_processor(const char **format, va_list arg);
static int			format_write(t_format_info *info, char *buf);
static void			format_read(const char **format, t_format_info *info);
static void			bit_flag_processor(t_format_info *info);

static const char	*g_pre_cha = " +-0x0X";

int	ft_printf(const char *format, ...)
{
	va_list		arg;
	int			ret;

	ret = 0;
	va_start(arg, format);
	while (*format && ret >= 0)
	{
		if (*format == '%')
		{
			++format;
			ret += format_processor(&format, arg);
			if (ret < 0)
				return (-1);
		}
		else
			ret += write(1, format, 1);
		++format;
	}
	va_end(arg);
	return (ret);
}

static int	format_processor(const char **format, va_list arg)
{
	t_format_info	info;
	char			buf[NUMERIC_BUF_SIZE];
	void			*buf_ptr;

	if (**format == '%')
		return (write(1, "%", 1));
	buf_ptr = (void *)buf;
	info = (t_format_info){0, 0, 0, 0, 0};
	format_read(format, &info);
	bit_flag_processor(&info);
	if (info.conv < 0)
		return (info.min_width);
	if (info.min_width < 0 || info.precision < 0
		|| (info.conv == 1 && g_conv_func[1](arg, &buf_ptr) < 0)
		|| (info.conv != 1 && g_conv_func[info.conv](arg, buf_ptr) < 0))
		return (INT_MIN);
	if (info.conv > 1 && *(char *)buf_ptr == '-')
	{
		info.bit_flag &= MAX_BIT ^ 8;
		info.bit_flag |= 32;
		buf_ptr = (char *)buf_ptr + 1;
	}
	if (info.bit_flag & 16 && buf[0] == '0' && !buf[1])
		info.bit_flag &= MAX_BIT ^ 16;
	return (format_write(&info, buf_ptr));
}

// len = length of arg.
// precision doesn't include preceding characters.
// minimum width include preceding charcters(' ', '-', '+').
static int	format_write(t_format_info *info, char *buf)
{
	int			len;
	int			ret;

	len = ft_strlen(buf) + (!info->conv && !buf[0]);
	info->precision += (info->bit_flag & 2 && info->min_width)
		* (info->min_width - !!(info->bit_flag & 16) - !!(info->bit_flag & 60));
	ret = 0;
	if (!(info->bit_flag & 1) && !(info->bit_flag & 2))
		ret += opt_padding(info, len);
	if (info->bit_flag & 60)
		ret += write(1, g_pre_cha + !!(info->bit_flag & 8)
				+ 2 * !!(info->bit_flag & 32)
				+ 3 * (info->conv == 6) + 5 * (info->conv == 7),
				1 + (info->conv == 6 || info->conv == 7));
	ret += opt_precision(info, buf, len);
	if ((info->bit_flag & 1) && !(info->bit_flag & 2))
		ret += opt_padding(info, len);
	return (ret);
}

static void	format_read(const char **format, t_format_info *info)
{
	char	*ptr;

	ptr = ft_strchr(g_flag_group, **format);
	while (ptr)
	{
		info->bit_flag |= 1 << (int)(ptr - (char *)g_flag_group);
		++*format;
		ptr = ft_strchr(g_flag_group, **format);
	}
	if (**format >= '0' && **format <= '9')
	{
		info->min_width = ft_atoi(*format);
		info->bit_len |= 1;
	}
	while (**format >= '0' && **format <= '9')
		++*format;
	if (**format == '.')
	{
		info->precision = ft_atoi(++*format);
		info->bit_len |= 2;
	}
	while (**format >= '0' && **format <= '9')
		++*format;
	ptr = ft_strchr(g_conv_group, **format);
	info->conv = -1 * (!ptr) + !!ptr * (ptr - (char *)g_conv_group);
}

static void	bit_flag_processor(t_format_info *info)
{
	info->bit_flag &= (MAX_BIT ^ (2 * (info->bit_flag & 1 || info->bit_len & 2
					|| info->conv == 1 || info->conv == 0)));
	info->bit_flag &= (MAX_BIT ^ (4 * (info->bit_flag & 8 || info->conv == 6
					|| info->conv == 7 || info->conv == 1 || info->conv == 0)));
	info->bit_flag &= (MAX_BIT ^ (8 * (info->conv == 8 || info->conv == 7
					|| info->conv == 6)));
	info->bit_flag &= (MAX_BIT ^ (16 * (info->conv != 6 && info->conv != 7)));
	info->bit_len &= 3 ^ (2 * (info->conv == 0 || info->conv == 2));
}
