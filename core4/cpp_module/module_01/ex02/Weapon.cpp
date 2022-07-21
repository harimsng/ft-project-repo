#include "Weapon.hpp" 
 
Weapon::Weapon() 
:
	m_type("")
{ 
} 
 
Weapon::~Weapon() 
{ 
} 

Weapon::Weapon(const std::string &type)
:
	m_type(type)
{
}

Weapon::Weapon(const char *type)
:
	m_type(type)
{
}
 
Weapon::Weapon(const Weapon &obj) 
{ 
	*this = obj;
} 
 
const Weapon &Weapon::operator=(const Weapon &obj) 
{ 
	this->m_type.assign(obj.m_type);
	return *this; 
}

// getter & setter
const std::string	&Weapon::getType(void) const
{
	return m_type;
}

void	Weapon::setType(const std::string &newType)
{
	m_type.assign(newType);
}
