/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:34:54 by hseong            #+#    #+#             */
/*   Updated: 2022/07/24 17:46:29 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	Harl	harl;

	if (argc != 2 || harl.filter(argv[1]) == false)
	{
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		return 0;
	}
}
