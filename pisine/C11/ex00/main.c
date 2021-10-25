/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:27:28 by hseong            #+#    #+#             */
/*   Updated: 2021/10/25 17:27:38 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#define	LEN		20

void	ft_foreach(int *tab, int length, void(*f)(int));
void	ft_putnbr(int nbr);

int	main(void)
{
	int		arr[LEN];
	int		idx;

	idx = 0;
	while (idx < LEN)
	{
		arr[idx] = idx;
		printf("%d ", arr[idx]);
		++idx;
	}
	printf("\n");
	ft_foreach(arr, LEN, ft_putnbr);
	ft_foreach(0, LEN, ft_putnbr);
	ft_foreach(arr, LEN, 0);
	ft_foreach(0, LEN, 0);
	return (0);
}

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	write(1, &("0123456789"[nbr % 10]), 1);
}
