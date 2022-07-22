#ifndef _HUMAN_B_
#define _HUMAN_B_ 
 
#include <string>

#include "Weapon.hpp"

class HumanB
{
private:
	const std::string	m_name;
	const Weapon		*m_weapon;

public:
	~HumanB();
	HumanB(const std::string &name);

	// getters & setters
	const std::string	&getName(void) const;
	void				setWeapon(const Weapon &newWeapon);
	const Weapon		*getWeapon(void) const;

	void	attack();
};
 
#endif
