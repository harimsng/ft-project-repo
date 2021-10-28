/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:37:56 by hseong            #+#    #+#             */
/*   Updated: 2021/10/28 19:22:26 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_hexd.h"

// $> hexdump nonexist
// hexdump: nonexist: No such file or directory
// hexdump: nonexist: Bad file descriptor
//
// $> hexdump .
// hexdump: .: Is a directory
//
// $> hexdump (-C)
// > (stdin)
//
// $< hexdump file1 nonexist file2 ...
// ..010 ....
// ..020 ....
// ...
// ..0a0 ....
// hexdump: nonexist: No such file or directory
// ..0b0 ....
// ...

void				print_error(char *filename);

int	main(int argc, char **argv)
{
	int				option;

	option = (argc > 1 && argv[1][0] == '-' && argv[1][1] == 'C' && argv[1][2] == 0);
	if (argc == 1 || (argc == 2 && option))
	{
		print_input(0, option);
		return (0);
	}
	while (--argc > 0)
	{
		if (print_input(*argv, option))
			print_error(*argv);
		++argv;
	}
	return (0);
}
