#ifndef _WEAPON_ 
#define _WEAPON_ 
 
class Weapon 
{ 
	Weapon(); 
	~Weapon(); 
	Weapon(const Weapon &obj); 
	const Weapon &operator=(const Weapon &obj); 
}; 
 
#endif
