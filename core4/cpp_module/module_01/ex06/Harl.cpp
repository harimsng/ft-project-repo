/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:33:40 by hseong            #+#    #+#             */
/*   Updated: 2022/07/24 17:53:44 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Harl.hpp"

Harl::Harl()
{
	m_FuncTab[0] = &Harl::info;
	m_FuncTab[1] = &Harl::debug;
	m_FuncTab[2] = &Harl::error;
	m_FuncTab[3] = &Harl::warning;
}

Harl::~Harl()
{
}

// private member functions
void	Harl::debug(void) const
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my \
7XL-double-cheese-triple-pickle-specialketchup burger. I really do!";
	std::cout << "\n\n";
}

void	Harl::info(void) const
{
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money. \
You didn’t put enough bacon in my burger! \
If you did, I wouldn’t be asking for more!";
	std::cout << "\n\n";
}

void	Harl::warning(void) const
{
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free. \
I’ve been coming for years whereas you started working here since last month.";
	std::cout << "\n\n";
}

void	Harl::error(void) const
{
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << "\n\n";
}

// public member function
int	Harl::complain(std::string level) const
{
	int		index;

	if (level.size() == 0)
		return -1;
	index = (level == "DEBUG")
		+ 2 * (level == "INFO")
		+ 3 * (level == "WARNING")
		+ 4 * (level == "ERROR") - 1;
	if (index < 0 || index >= MSG_NUM)
		return -1;
	return index;
}

bool	Harl::filter(const std::string level) const
{
	switch (complain(level))
	{
	case 0:
		debug();
	case 1:
		info();
	case 2:
		warning();
	case 3:
		error();
		break;
	default:
		return false;
	}
	return true;
}
