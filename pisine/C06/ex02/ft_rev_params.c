/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:51:00 by hseong            #+#    #+#             */
/*   Updated: 2021/10/18 18:52:34 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str);

int	main(int argc, char **argv)
{
	int		idx;

	idx = argc - 1;
	while (idx > 0)
	{
		ft_putstr(argv[idx]);
		write(1, "\n", 1);
		--idx;
	}
	return (0);
}

void	ft_putstr(char *str)
{
	while (*str != 0)
		write(1, str++, 1);
}
