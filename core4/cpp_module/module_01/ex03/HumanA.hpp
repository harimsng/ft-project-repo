#ifndef _HUMAN_A_ 
#define _HUMAN_A_ 
 
#include <string>

#include "Weapon.hpp"

class HumanA 
{ 
private:
	std::string		m_name;
	const Weapon	*m_weapon;
	const Weapon	m_defaultWeapon;

public:
	HumanA(); 
	~HumanA(); 
	HumanA(const std::string &name, Weapon &weapon);
	HumanA(const HumanA &obj); 
	const HumanA &operator=(const HumanA &obj); 

	// getters & setters
	void				setName(const std::string &newName);
	const std::string	&getName(void) const;
	void				setWeapon(const Weapon &newWeapon);
	const Weapon		*getWeapon(void) const;

	void	attack();
}; 
 
#endif
