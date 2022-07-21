#include <iostream>

#include "HumanA.hpp" 
 
HumanA::HumanA() 
:
	m_name("Anonymous"),
	m_defaultWeapon("Fist")
{ 
	m_weapon = &m_defaultWeapon;
} 
 
HumanA::~HumanA() 
{ 
} 
 
HumanA::HumanA(const HumanA &obj)
{
	(void)obj;
}

HumanA::HumanA(const std::string &name, Weapon &weapon) 
:
	m_name(name),
	m_weapon(&weapon)
{ 
} 
 
const HumanA &HumanA::operator=(const HumanA &obj) 
{ 
	this->m_name.assign(obj.m_name);
	this->m_weapon = obj.m_weapon;
	return *this; 
}

// getters & setters
void	HumanA::setName(const std::string &newName)
{
	m_name.assign(newName);
}

const std::string	&HumanA::getName(void) const
{
	return m_name;
}

void	HumanA::setWeapon(const Weapon &newWeapon)
{
	m_weapon = &newWeapon;
}

const Weapon	*HumanA::getWeapon(void) const
{
	return m_weapon;
}

// public methods
void	HumanA::attack(void)
{
	if (m_weapon == NULL)
	{
		std::cout << m_name << " has no weapon\n";
		return;
	}
	std::cout << m_name << " attacks with their weapon ";
	std::cout << m_weapon->getType() << std::endl;
}
