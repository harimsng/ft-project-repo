/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:40:08 by hseong            #+#    #+#             */
/*   Updated: 2021/11/29 18:40:19 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# define INT_MAX 2147483647

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
	unsigned char	*str;
}					t_buf;

char		*get_next_line(int fd);
void		*ft_memcpy(void *dest, const void *src, size_t size);
void		*ft_calloc(size_t count, size_t size);

#endif
