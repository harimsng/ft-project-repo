#ifndef _HUMAN_A_ 
#define _HUMAN_A_ 
 
#include <string>

#include "Weapon.hpp"

class HumanA 
{ 
private:
	const std::string	m_name;
	const Weapon		&m_weapon;

public:
	~HumanA(); 
	HumanA(const std::string &name, const Weapon &weapon);

	// getters & setters
	const std::string	&getName(void) const;
	const Weapon		&getWeapon(void) const;

	void	attack();
}; 
 
#endif
