#include <iostream>

#include "HumanA.hpp" 
 
HumanA::~HumanA() 
{ 
} 
 
HumanA::HumanA(const std::string &name, const Weapon &weapon) 
:
	m_name(name),
	m_weapon(weapon)
{ 
} 
 
// getters & setters
const std::string	&HumanA::getName(void) const
{
	return m_name;
}

const Weapon	&HumanA::getWeapon(void) const
{
	return m_weapon;
}

// public methods
void	HumanA::attack(void)
{
	std::cout << m_name << " attacks with their weapon ";
	std::cout << m_weapon.getType() << std::endl;
}
