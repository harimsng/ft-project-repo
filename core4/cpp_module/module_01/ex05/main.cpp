/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:34:09 by hseong            #+#    #+#             */
/*   Updated: 2022/07/24 17:34:09 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <climits>
#include <iostream>

#include "Harl.hpp"

int	main(void)
{
	Harl		harl;

	for (unsigned long long int str = 0, i = 0;
			str < (ULLONG_MAX >> 33);
			++str)
	{
		if (str % ((ULLONG_MAX >> 33) / 1000) == 0)
			std::cout << i++ * 0.1 << "%\n";
		harl.complain((char *)&str);
	}
	return 0;
}
