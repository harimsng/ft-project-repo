#include "Contact.hpp"

Contact::Contact(size_t index):
	_index(index),
	_firstName(""),
	_lastName(""),
	_nickname(""),
	_phoneNumber(""),
	_darkestSecret("")
{
}

bool	Contact::_getStringInput(char str[NAME_SIZE])
{
	std::cin.get(str, NAME_SIZE);
	if (std::cin.fail() == true)
		std::cout << "an error occured during input\n";
	return true;
}

void	Contact::setIndex(size_t index)
{
	this->_index = index;
}

size_t		Contact::getIndex(void) const
{
	return this->_index;
}

void		Contact::setFirstName(const char newFirstName[NAME_SIZE])
{
	for (int i = 0; i < NAME_SIZE; ++i)
		_firstName[i] = newFirstName[i];
}

const char	[NAME_SIZE]&Contact::getFirstName(void) const
{
	return this->_firstName;
}

void		Contact::setLastName(const char newLastName[NAME_SIZE])
{

}

const char	*&Contact::getLastName(void) const
{
}

void		Contact::setNickname(const char newNickname[NAME_SIZE])
{

}

const char	*&Contact::getNickname(void) const
{

}

void		Contact::setPhoneNumber(const char phoneNumber[NAME_SIZE])
{

}

const char	*&Contact::getPhoneNumber(void) const
{

}

void		Contact::setDarkestSecret(const char darkestSecret[NAME_SIZE])
{

}

const char	*&Contact::getDarkestSecret(void) const
{

}
