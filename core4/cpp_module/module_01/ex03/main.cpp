#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);

		bob.attack();
		club.setType("some other type of club");
		bob.attack();

		Weapon *clubPtr = new Weapon("dynamic club");
		HumanA bab("Bab", *clubPtr);

		bab.attack();
		clubPtr->setType("dangerous club");
		bab.attack();
		delete clubPtr;
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");

		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	system("leaks $$");
	return 0;
}
