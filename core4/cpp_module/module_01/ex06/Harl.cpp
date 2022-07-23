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
7XL-double-cheese-triple-pickle-specialketchup burger. I really do!";
}

void	Harl::info(void) const
{

	std::cout << "I cannot believe adding extra bacon costs more money. \
You didn’t put enough bacon in my burger! \
If you did, I wouldn’t be asking for more!";
}

void	Harl::warning(void) const
{
	std::cout << "I think I deserve to have some extra bacon for free. \
I’ve been coming for years whereas you started working here since last month.";
}

void	Harl::error(void) const
{
	std::cout << "This is unacceptable! I want to speak to the manager now.";
}

// public member function

/*
 * DEBUG	'D' = 68 = 0b01000100 -> & 7 = 4 -> -1 = 3 -> /2 = 1
 * INFO		'I' = 73 = 0b01001001 -> & 7 = 1 -> -1 = 0 -> /2 = 0
 * WARNING	'W' = 87 = 0b01010111 -> & 7 = 7 -> -1 = 6 -> /2 = 3
 * ERROR	'E' = 69 = 0b01000101 -> & 7 = 5 -> -1 = 4 -> /2 = 2
 */
void	Harl::complain(std::string level) const
{
	int		index;

	if (level.size() == 0)
	{
		std::cout << "invalid input\n";
		return;
	}
	index = level[0] & 7;
	index = (index - 1) / 2;
	if (index < 0 || index >= MSG_NUM)
		return;
	(this->*m_FuncTab[index])();
}
