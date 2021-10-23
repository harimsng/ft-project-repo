/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:41:10 by hseong            #+#    #+#             */
/*   Updated: 2021/10/23 20:25:50 by hseong           ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"
#include "../includes/ft_dict.h"

int		parser(char *filename, t_dict **arr, int *arr_len);
void	error_detect(int num);

int	main(int argc, char **argv)
{
	char		*filename;
	t_dict		*arr;
	int			arr_len;
	int			idx;

	filename = "numbers.dict";
	if (argc == 1 || argc > 3)
	{
		ft_putstr("Error\n");
		return (0);
	}
	else if (argc == 3)
		filename = argv[1];
	error_detect(parser(filename, &arr, &arr_len));
	idx = 0;
	while (idx < arr_len)
	{
		ft_putstr("key  :\t");
		ft_putnbr(arr[idx].key);
		ft_putstr("\tvalue:\t");
		ft_putstr(arr[idx].value);
		ft_putstr("\n");
		++idx;
	}
	//free each arr.value and arr
	return (0);
}

void	error_detect(int num)
{
	if (num == -1)
		ft_putstr("Dict Error\n");
	else if (num == -2)
		ft_putstr("Malloc Error\n");
}
