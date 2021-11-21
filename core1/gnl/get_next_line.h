/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 22:35:48 by hseong            #+#    #+#             */
/*   Updated: 2021/11/22 03:01:45 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_line
{
	int		size;
	char	*str;
}			t_line;

typedef struct s_buf
{
	int		fd;
	int		eof;
	char	buf[BUFFER_SIZE + 1];
}			t_buf;

char		*get_next_line(int fd);
char		*ft_strdup(const char *s);
char		*ft_strcpy(char *dest, const char *src);
void		*ft_memset(void *addr, int c, size_t size);
size_t		ft_strlen(const char *s);

#endif
