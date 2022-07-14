#include "Contact.hpp"

Contact::Contact():
	m_index(-1),
	m_firstName(""),
	m_lastName(""),
	m_nickname(""),
	m_phoneNumber(""),
	m_darkestSecret("")
{
	this->setGSetterTable();
}

Contact::Contact(int index):
	m_index(index),
	m_firstName(""),
	m_lastName(""),
	m_nickname(""),
	m_phoneNumber(""),
	m_darkestSecret("")
{
	this->setGSetterTable();
}

Contact::~Contact()
{
}

void	Contact::setGSetterTable(void)
{
	this->m_getterTable[0] = &Contact::getFirstName;
	this->m_getterTable[1] = &Contact::getLastName;
	this->m_getterTable[2] = &Contact::getNickname;
	this->m_getterTable[3] = &Contact::getPhoneNumber;
	this->m_getterTable[4] = &Contact::getDarkestSecret;
	this->m_setterTable[0] = &Contact::setFirstName;
	this->m_setterTable[1] = &Contact::setLastName;
	this->m_setterTable[2] = &Contact::setNickname;
	this->m_setterTable[3] = &Contact::setPhoneNumber;
	this->m_setterTable[4] = &Contact::setDarkestSecret;
}

void	Contact::setIndex(int index)
{
	this->m_index = index;
}

int		Contact::getIndex(void) const
{
	return this->m_index;
}

void		Contact::setFirstName(const char newFirstName[NAME_SIZE])
{
	int		i = 0;
	for (; i < NAME_SIZE; ++i)
		m_firstName[i] = newFirstName[i];
	m_firstName[i] = '\0';
}

const Contact::t_fixedArr	&Contact::getFirstName(void) const
{
	return this->m_firstName;
}

void		Contact::setLastName(const char newLastName[NAME_SIZE])
{
	int		i = 0;
	for (; i < NAME_SIZE; ++i)
		m_lastName[i] = newLastName[i];
	m_firstName[i] = '\0';
}

const Contact::t_fixedArr	&Contact::getLastName(void) const
{
	return this->m_lastName;
}

void		Contact::setNickname(const char newNickname[NAME_SIZE])
{
	int		i = 0;
	for (; i < NAME_SIZE; ++i)
		m_nickname[i] = newNickname[i];
	m_firstName[i] = '\0';
}

const Contact::t_fixedArr	&Contact::getNickname(void) const
{
	return this->m_nickname;
}

void		Contact::setPhoneNumber(const char newPhoneNumber[NAME_SIZE])
{
	int		i = 0;
	for (; i < NAME_SIZE; ++i)
		m_phoneNumber[i] = newPhoneNumber[i];
}

const Contact::t_fixedArr	&Contact::getPhoneNumber(void) const
{
	return this->m_phoneNumber;
}

void		Contact::setDarkestSecret(const char newDarkestSecret[NAME_SIZE])
{
	int		i = 0;
	for (; i < NAME_SIZE; ++i)
		m_darkestSecret[i] = newDarkestSecret[i];
	m_firstName[i] = '\0';
}

const Contact::t_fixedArr	&Contact::getDarkestSecret(void) const
{
	return this->m_darkestSecret;
}
