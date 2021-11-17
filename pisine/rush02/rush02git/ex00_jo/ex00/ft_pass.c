/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pass.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejo <hyejo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 11:54:15 by hyejo             #+#    #+#             */
/*   Updated: 2021/10/24 12:52:18 by hyejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	ft_pass_num(int fd)
{
	char	ch;
	int		colon;
	int		space;

	colon = 0;
	space = 0;
	while (read(fd, &ch, 1))
	{
		if (('0' <= ch && ch <= '9') || (ch == ' ' && colon == 0))
			continue ;
		if (ch == ':' && colon == 0)
		{
			colon = 1;
			continue ;
		}
		if (ch == ' ' && space == 0)
		{
			space = 1;
			continue ;
		}
		return (ch);
	}
	return (ch);
}

void	ft_pass(int fd, int index)
{
	int		i;
	char	ch;

	i = 0;
	while (i < index)
	{
		while (read(fd, &ch, 1))
		{
			if (ch == '\n')
				break ;
		}
		i++;
	}
}
