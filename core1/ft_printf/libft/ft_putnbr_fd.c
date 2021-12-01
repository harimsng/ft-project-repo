/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:23:10 by hseong            #+#    #+#             */
/*   Updated: 2021/12/01 17:45:34 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

static int	check_num(int *n, int fd);

int	ft_putnbr_fd(int n, int fd)
{
	const char	*tab = "0123456789";
	int			denom;
	int			ret;

	ret = check_num(&n, fd);
	if (ret > 0)
		return (ret);
	ret = n < 0;
	write(1, "-", ret);
	n *= 1 - 2 * ret;
	denom = 1000000000;
	while (n / denom == 0)
		denom /= 10;
	while (denom > 0)
	{
		ret += write(fd, tab + n / denom, 1);
		n %= denom;
		denom /= 10;
	}
	return (ret);
}

int	check_num(int *n, int fd)
{
	if (*n == -2147483648)
		return (write(fd, "-2147483648", 11));
	else if (*n == 0)
		return (write(fd, "0", 1));
	return (0);
}
