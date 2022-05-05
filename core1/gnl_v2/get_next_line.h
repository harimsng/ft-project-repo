/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 21:10:12 by hseong            #+#    #+#             */
/*   Updated: 2022/04/30 12:20:58 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE (64)
# endif
# ifndef NULL
#  define NULL ((void *)0)
# endif

# define HASHMAP_SIZE (1024)
# define LINEEND (1)

# define SUCCESS (0)
# define FAIL (1)

typedef struct s_buffer
{
	char	str[BUFFER_SIZE];
	size_t	size;
}		t_buffer;

typedef struct s_line
{
	char	*str;
	size_t	size;
}		t_line;

typedef struct s_node
{
	char			str[BUFFER_SIZE];
	int				fd;
	int				size;
	struct s_node	*next;
}		t_node;

// utility functions
size_t	ft_strlcpy(char *dst, const char *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
int		append_line(t_line *line, t_buffer *buf, size_t len);

#endif
