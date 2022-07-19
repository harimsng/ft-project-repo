#include <string>

#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	class Zombie	*allocatedZombie = new Zombie(name);

	return allocatedZombie;
}
