#include "PhoneBook.hpp"
#include <ios>

static const char 	*g_promptTable[NUM_DATA] = {
	"input a first name.\n> ",
	"input a last name.\n> ",
	"input a nickname.\n> ",
	"input a phone number.\n> ",
	"input the darkest secret.\n> ",
};

PhoneBook::PhoneBook():
	m_phoneBookStartIdx(0),
	m_phoneBookSize(0)
{
}

PhoneBook::~PhoneBook()
{
}

bool	PhoneBook::addContact(void)
{
	Contact	*contact;
	char	buffer[NAME_SIZE] = {0, };
	int		phoneBookIdx;

	if (m_phoneBookSize == MAX_CONTACT)
		return false;
	std::cout << "input fields to make a contact\n";
	phoneBookIdx = this->m_phoneBookStartIdx + this->m_phoneBookSize;
	phoneBookIdx %= MAX_CONTACT;
	contact = this->m_phoneBook + phoneBookIdx;
	for (int i = 0; i < NUM_DATA; ++i)
	{
		std::cout << g_promptTable[i];
		if (getStringInput(buffer) == false)
			return false;
		(contact->*(contact->m_setterTable[i]))(buffer);
	}
	return true;
}

bool	PhoneBook::getStringInput(char str[NAME_SIZE])
{
	bool			loopFlag = true;
	std::streamsize	count = 0;

	while (loopFlag)
	{
		std::cin.getline(str, NAME_SIZE + 1);
		count = std::cin.gcount();
		switch (count)
		{
			case NAME_SIZE:
				std::cout << "input string is too long.\
there must be less than "
					<< NAME_SIZE << " characters.\n";
				break;
			case 0:
				std::cout << "there must be input.\n";
				break;
			default:
				loopFlag = false;
		}
	}
	if (std::cin.fail() == true)
		std::cout << "an error occured during input\n";
	return true;
}

bool	PhoneBook::searchContact(void)
{
	int		idx;

	std::cout << "input an index.\n";
	std::cin >> idx;
	if (this->m_phoneBook[idx].getIndex() == -1)
	{
		std::cout << "it's an empty index.\n";
		return false;
	}
	
	return true;
}

static void	printInternal(Contact *contact)
{
	const char	*strPtr;

	std::cout << '|';
	std::cout << std::cout.width(10) << contact->getIndex() << '|';
	std::cout << '|';
	for (int i = 0; i < NUM_DATA; ++i)
	{
		strPtr = (contact->*(contact->m_getterTable[i]))();
		if (strlen(strPtr) > 9)
		{
			std::cout << '.';
			std::cout.write(strPtr + strlen(strPtr) - 9, 9);
		}
		else
			std::cout << std::cout.width(10) << strPtr;
		std::cout << '|';
	}
}
