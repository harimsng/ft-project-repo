/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:50:35 by hseong            #+#    #+#             */
/*   Updated: 2021/10/18 18:50:49 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str);

int	main(int argc, char **argv)
{
	if (argc > 0)
	{
		ft_putstr(*argv);
		ft_putstr("\n");
	}
	return (0);
}

void	ft_putstr(char *str)
{
	while (*str != 0)
		write(1, str++, 1);
}
