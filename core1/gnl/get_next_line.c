/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 22:35:55 by hseong            #+#    #+#             */
/*   Updated: 2021/11/18 23:20:45 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE];
	char		*temp_ptr;
	size_t		diff;

	ft_memset(buf, 0, BUFFER_SIZE);
	read_size = read(fd, buf, BUFFER_SIZE);
	while (1)
	{
		temp_ptr = ft_strchr(buf, 10);
		if (temp_ptr)
		{
			diff = temp_ptr - buf;
			buf[diff] = 0;
			return join_free(buf, diff);
		}
		if (read_size < BUFFER_SIZE)
		{
			return ;
		}
		ft_memset(buf, 0, BUFFER_SIZE);
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	return (NULL); 
}
