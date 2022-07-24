/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:34:05 by hseong            #+#    #+#             */
/*   Updated: 2022/07/24 17:47:33 by hseong           ###   ########.fr       */
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
	std::cout << "I love having extra bacon for my \
7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void	Harl::info(void) const
{

	std::cout << "I cannot believe adding extra bacon costs more money. \
You didn’t put enough bacon in my burger! \
If you did, I wouldn’t be asking for more!\n";
}

void	Harl::warning(void) const
{
	std::cout << "I think I deserve to have some extra bacon for free. \
I’ve been coming for years whereas you started working here since last month.\n";
}

void	Harl::error(void) const
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

// public member function
void	Harl::complain(std::string level) const
{
	int		index;

	index = (level == "INFO")
		+ 2 * (level == "DEBUG")
		+ 3 * (level == "ERROR")
		+ 4 * (level == "WARNING");
	--index;
	if (index < 0 || index >= MSG_NUM)
		return;
	(this->*m_FuncTab[index])();
}
