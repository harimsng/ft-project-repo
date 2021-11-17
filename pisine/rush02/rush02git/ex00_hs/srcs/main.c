/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejo <hyejo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 10:06:22 by hyejo             #+#    #+#             */
/*   Updated: 2021/10/24 20:33:29 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"
#include "../includes/ft_dict.h"

static const char	*g_filename = "numbers.dict";
int					parser(const char *g_filename, t_dict **arr, int *dict_size);
int					error_handle(int argc, char **argv, int parsernum);
int					set_dict(t_dict *ref_dict, t_dict *dict_arr, int dict_size);
void				sort_dict(t_dict *dict_arr, int dict_size);

int	main(int argc, char **argv)
{
	t_dict			*dict_arr;
	t_dict			*ref_dict;
	int				dict_size;
	int				idx;

	if (error_handle(argc, argv, parser(g_filename, &dict_arr, &dict_size)))
		return (0);
	if (argc == 3)
		g_filename = argv[1];

	ref_dict = (t_dict *)malloc(sizeof(t_dict) * 41);
	sort_dict(dict_arr, dict_size);
	set_dict(ref_dict, dict_arr, dict_size);
//	ft_print_num(num, dict_arr, dict_size);
//	write(1, "\n", 1);
	idx = 0;
	while (idx < 41)
	{
		ft_putnbr(ref_dict[idx].key);
		ft_putstr(ref_dict[idx].value);
		free(ref_dict[idx++].value);
	}
	free(dict_arr);
	return (0);
}

// **** input number have to be unsigned int (not atoi number) ****
int	error_handle(int argc, char **argv, int parsernum)
{
	if (argc == 1 || argc > 3 || ft_atou(argv[argc - 1]) == -1)
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (parsernum == -1)
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	if (parsernum == -2)
	{
		ft_putstr("Error\n");
		return (1);
	}
	return (0);
}
