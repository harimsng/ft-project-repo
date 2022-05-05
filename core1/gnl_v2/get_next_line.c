/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 21:14:13 by hseong            #+#    #+#             */
/*   Updated: 2022/04/30 12:26:56 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	hashtab_load(t_node *hashtab, t_buffer *buf, int fd);
static void	hashtab_save(t_node *hashtab, t_buffer *buf, int fd);
static int	hashtab_find(t_node **hashtab, t_buffer *buf, int fd);
static int	process_line(t_line *line, t_buffer *buf);

char	*get_next_line(int fd)
{
	static t_node	hashtab[HASHMAP_SIZE];
	t_buffer		buf;
	t_line			line;

	line = (t_line){ft_memset(malloc(128), 0, 128), 0};
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	hashtab_load(hashtab + fd % 1024, &buf, fd);
	buf.size += read(fd, buf.str + buf.size, BUFFER_SIZE - buf.size);
	while (!process_line(&line, &buf))
		buf.size = read(fd, buf.str, BUFFER_SIZE);
	if (buf.size != BUFFER_SIZE)
		hashtab_save(hashtab + fd % 1024, &buf, fd);
	ft_strlcpy(line.str, buf.str, buf.size);
	return (line.str);
}

void	hashtab_save(t_node *hashtab, t_buffer *buf, int fd)
{
	if (hashtab_find(&hashtab, buf, fd) == 0)
	{
		hashtab->next = malloc(sizeof(t_node));
		if (hashtab->next == NULL)
			return ;
		*hashtab->next = (t_node){{0, }, fd, buf->size, NULL};
		ft_strlcpy(hashtab->next->str, buf->str, buf->size);
		return ;
	}
	ft_strlcpy(hashtab->str, buf->str, buf->size);
	hashtab->size = buf->size;
}

void	hashtab_load(t_node *hashtab, t_buffer *buf, int fd)
{
	t_node	*node;

	*buf = (t_buffer){{0, }, 0};
	if (hashtab_find(&hashtab, buf, fd) == FAIL)
		return ;
	ft_strlcpy(buf->str, hashtab->str, hashtab->size);
	buf->size = hashtab->size;
	node = hashtab;
}

int	hashtab_find(t_node **hashtab, t_buffer *buf, int fd)
{
	t_node	*node;

	node = *hashtab;
	while (node->next != NULL && node->fd != fd)
		node = node->next;
	*hashtab = node;
	if (node->next == NULL && node->fd != fd)
		return (FAIL);
	return (SUCCESS);
}

int	process_line(t_line *line, t_buffer *buf)
{
	int		idx = 0;

	while (idx < buf->size && buf->str[idx] != '\n')
		++idx;
	if (idx < buf->size || buf->size != BUFFER_SIZE
		|| buf->str[buf->size] == '\n')
	{
		append_line(line, buf, idx);
		ft_strlcpy(buf->str, buf->str + idx, buf->size - idx);
		buf->size -= idx;
		return (LINEEND);
	}
	append_line(line, buf, idx);
	return (0);
}
