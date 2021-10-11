/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:19:57 by hseong            #+#    #+#             */
/*   Updated: 2021/10/11 16:12:47 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_addr(char *ptr);
void	print_hex(char c);
void	print_hexcontent(char *ptr, int len);
void	print_content(char *ptr, int len);

void	*ft_print_memory(void *addr, unsigned int size)
{
	char			*ptr;
	unsigned int	idx;
	int				sub_len;

	ptr = addr;
	idx = 0;
	while (idx < size)
	{
		sub_len = 16 * (size >= idx + 16) + (size - idx) * (size < idx + 16);
		print_addr(ptr);
		print_hexcontent(ptr, sub_len);
		print_content(ptr, sub_len);
		write(1, "\n", 1);
		ptr += 16;
		idx += 16;
	}
	return (addr);
}

void	print_addr(char	*ptr)
{
	int				bit;
	long long int	hex;

	bit = 60;
	while (bit >= 0)
	{
		hex = ((long long int)ptr >> bit) & 15;
		print_hex((char)hex);
		bit -= 4;
	}
	write(1, ":", 1);
	write(1, " ", 1);
}

// hex range should be [0, 15]
void	print_hex(char hex)
{
	if (hex > 15)
	{
		write(1, "-1", 1);
		return ;
	}
	else if (hex > 9)
	{
		hex = 'a' + hex - 10;
		write(1, &hex, 1);
	}
	else
	{
		hex = '0' + hex;
		write(1, &hex, 1);
	}
}

void	print_hexcontent(char *ptr, int len)
{
	while (len > 0)
	{
		print_hex(*ptr >> 4);
		print_hex(*ptr & 15);
		print_hex(ptr[1] >> 4);
		print_hex(ptr[1] & 15);
		ptr += 2;
		len -= 2;
		write(1, " ", 1);
	}
}

// size should be valid
void	print_content(char *ptr, int len)
{
	while (len > 0)
	{
		if (*ptr < 32)
			write(1, ".", 1);
		else
			write(1, ptr, 1);
		++ptr;
		--len;
	}
}
