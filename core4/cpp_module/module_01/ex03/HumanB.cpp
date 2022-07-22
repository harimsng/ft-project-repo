#include <iostream>

#include "HumanB.hpp" 
 
HumanB::~HumanB()
{
}
 
HumanB::HumanB(const std::string &name)
:
	m_name(name),
	m_weapon(NULL)
{
}
 
// getters & setters
const std::string	&HumanB::getName(void) const
{
	return m_name;
}

void	HumanB::setWeapon(const Weapon &newWeapon)
{
	m_weapon = &newWeapon;
}

const Weapon	*HumanB::getWeapon(void) const
{
	return m_weapon;
}

// public methods
void	HumanB::attack(void)
{
	if (m_weapon == NULL)
	{
		std::cout << m_name << " has no weapon\n";
		return;
	}
	std::cout << m_name << " attacks with their weapon ";
	std::cout << m_weapon->getType() << std::endl;
}
