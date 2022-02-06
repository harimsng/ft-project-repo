/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 21:10:12 by hseong            #+#    #+#             */
/*   Updated: 2022/01/25 13:42:13 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>

# define NULL ((void *)0)

typedef struct
{
	char	str[BUFFER_SIZE];
	size_t	size;
}		t_line;

typedef struct s_data
{
	struct s_data	*next;
	char			*str;
	int				fd;
	int				size;
}		t_data;

// utility functions
size_t	ft_strlcpy(char *dst, const char *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
int		storage_chaining(t_data *storage, t_buf *buf, int fd);
void	storage_free(t_data **storage, int fd);

#endif
