/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejo <hyejo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 10:06:22 by hyejo             #+#    #+#             */
/*   Updated: 2021/10/24 21:17:56 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
// #include <stdio.h>

// void	print_dict(t_dicts dicts)
// {
// 	int	j;

// 	printf("size: %d\n", dicts.size);
// 	j = 0;
// 	while (j < dicts.size)
// 	{
// 		printf("num : %d, name: %s\n", dicts.dicts[j].num, dicts.dicts[j].name);
// 		j++;
// 	}
// }

static const char	*g_dict = "numbers.dict";

int	main(int argc, char **argv)
{
	t_dicts		dicts;
	long long	num;

	if (argc == 1 || argc > 3)
	{
		ft_putstr("Error\n");
		return (0);
	}
	else if (argc == 3)
		g_dict = argv[1];
	dicts = ft_get_dicts((char *)g_dict);
	num = ft_atoi(argv[argc - 1]);
	if (num < 0)
		write(1, "error\n", 6);
	else
	{
		ft_print_num(num, dicts);
		write(1, "\n", 1);
	}
	free(dicts.dicts);
	return (0);
}
