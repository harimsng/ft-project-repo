#ifndef _WEAPON_ 
#define _WEAPON_ 

#include <string>
 
class Weapon 
{ 
private:
	std::string m_type;

public:
	Weapon(); 
	~Weapon(); 
	Weapon(const std::string &type); 
	Weapon(const Weapon &obj); 
	Weapon(const char *type);
	const Weapon &operator=(const Weapon &obj); 

	// getter & setter
	const std::string	&getType() const;
	void				setType(const std::string &newType);
}; 
 
#endif
