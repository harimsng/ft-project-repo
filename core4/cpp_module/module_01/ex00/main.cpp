#include <cstdlib>
#include <string>

#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	Zombie	zombie1("Kim");
	Zombie	*p_Zombie;
	Zombie	*p_Zombie2;

	p_Zombie = newZombie("John");
	randomChump("Lee");
	delete p_Zombie;
	p_Zombie = new Zombie("James");
	randomChump("Stack");
	p_Zombie2 = new Zombie("Heap");
	delete p_Zombie2;
	delete p_Zombie;
	return 0;
}
