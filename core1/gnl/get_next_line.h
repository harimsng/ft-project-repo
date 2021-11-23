/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 22:35:48 by hseong            #+#    #+#             */
/*   Updated: 2021/11/23 15:38:26 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_line
{
	int				cap;
	int				size;
	unsigned char	*str;
}					t_line;

typedef struct s_buf
{
	int				fd;
	int				size;
	unsigned char	str[BUFFER_SIZE + 1];
}					t_buf;

char		*get_next_line(int fd);
void		*ft_memcpy(void *dest, const void *src, size_t size);

#endif
