#ifndef _HUMAN_B_
#define _HUMAN_B_ 
 
#include <string>

#include "Weapon.hpp"

class HumanB
{
private:
	std::string		m_name;
	const Weapon	*m_weapon;

public:
	HumanB();
	~HumanB();
	HumanB(const std::string &name);
	HumanB(const HumanB &obj);
	const HumanB &operator=(const HumanB &obj);

	// getters & setters
	void 				setName(const std::string &newName);
	const std::string	&getName(void) const;
	void				setWeapon(const Weapon &newWeapon);
	const Weapon		*getWeapon(void) const;

	void	attack();
};
 
#endif
