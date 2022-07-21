#include <iostream>

#include "HumanB.hpp" 
 
HumanB::HumanB() 
:
	m_name("Anonymous"),
	m_weapon(NULL)
{ 
} 
 
HumanB::~HumanB() 
{ 
} 
 
HumanB::HumanB(const HumanB &obj)
{
	(void)obj;
}

HumanB::HumanB(const std::string &name)
:
	m_name(name)
{ 
} 
 
const HumanB &HumanB::operator=(const HumanB &obj) 
{ 
	this->m_name.assign(obj.m_name);
	this->m_weapon = obj.m_weapon;
	return *this; 
}

// getters & setters
void	HumanB::setName(const std::string &newName)
{
	m_name.assign(newName);
}

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
