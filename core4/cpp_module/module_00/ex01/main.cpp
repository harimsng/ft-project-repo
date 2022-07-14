#include <iostream>

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	inputStr;
	int			index = 0;
	bool		loopFlag = true;

	std::cout << "Welcome to phone book service.\n";
	while (loopFlag && std::cin.eof() == false)
	{
		std::cout << "> ";
		std::cin >> inputStr;
		index = (inputStr == "ADD")
			+ 2 * (inputStr == "SEARCH")
			+ 3 * (inputStr == "EXIT");
		switch (index)
		{
			case 1:
				phoneBook.addContact();
				break;
			case 2:
				phoneBook.searchContact();
				break;
			case 3:
				loopFlag = false;
				break;
		}
	}
	return 0;
}
