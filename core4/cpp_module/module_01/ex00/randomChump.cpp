#include <string>

#include "Zombie.hpp"

void	randomChump(std::string name)
{
	class Zombie	stackZombie(name);
	
	stackZombie.announce();
}
