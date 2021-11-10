/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:23:10 by hseong            #+#    #+#             */
/*   Updated: 2021/11/10 18:30:04 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

static int			check_num(int *n);

void	ft_putnbr_fd(int n, int fd)
{
	const char	*tab = "0123456789";
	int			denom;

	if (check_num(&n, fd))
		return ;
	denom = 1000000000;
	while (n / denom == 0)
		denom /= 10;
	while (denom > 0)
	{
		write(fd, tab + n / denom, 1);
		n = n % denom;
		denom /= 10;
	}
}

int	check_num(int *n, int fd)
{
	if (*n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (1);
	}
	else if (*n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	else if (*n < 0)
	{
		*n *= -1;
		return (0);
	}
	return (0);
}
