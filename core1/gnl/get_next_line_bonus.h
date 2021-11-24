/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:35:33 by hseong            #+#    #+#             */
/*   Updated: 2021/11/24 20:36:52 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
