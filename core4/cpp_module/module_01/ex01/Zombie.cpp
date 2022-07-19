/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:16:26 by hseong            #+#    #+#             */
/*   Updated: 2022/07/19 15:53:09 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "CONSTRUCT: default\n";
}

Zombie::Zombie(const std::string &name):
	m_name(name)
{
	std::cout << "CONSTRUCT: \"";
	std::cout << m_name;
	std::cout << "\"\n";
}

Zombie::~Zombie()
{
	std::cout << "DESTRUCT: \"";
	std::cout << m_name;
	std::cout << "\"\n";
}

// setter
void	Zombie::setName(std::string &name)
{
	m_name = name;
	announce();
}

// member function
void	Zombie::announce(void)
{
	std::cout << m_name << ": BraiiiiiiinnnzzzZ...\n";
}
