/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:41:10 by hseong            #+#    #+#             */
/*   Updated: 2021/10/24 16:25:39 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"
#include "../includes/ft_dict.h"

int		parser(const char *filename, t_dict **arr, int *arr_len);
int		error_detect(int num);
int		arg_check(int argc, char **argv);

static const char	*filename = "numbers.dict";

int	main(int argc, char **argv)
{
	t_dict		*arr;
	int			arr_len;
	int			idx;

	if (arg_check(argc, argv)
			|| error_detect(parser(filename, &arr, &arr_len)))
		return (0);
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
	//translate(argv[argc - 1]);
	idx = 0;
	while (idx < arr_len)
		free(arr[idx++].value);
	free(arr);
	return (0);
}

int	arg_check(int argc, char **argv)
{
	if (argc == 1 || argc > 3 || ft_atou(argv[argc - 1]) == -1)
	{
		ft_putstr("Error\n");
		return (1);
	}
	else if (argc == 3)
		filename = argv[1];
	return (0);	
}

int	error_detect(int num)
{
	if (num == -1)
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	else if (num == -2)
	{
		ft_putstr("Malloc Error\n");
		return (1);
	}
	return (0);
}
