/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 02:27:03 by hseong            #+#    #+#             */
/*   Updated: 2022/07/15 05:18:05 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// move this to more proper place
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

void		Contact::setFirstName(const char newFirstName[MAX_NAME])
{
	int		i = 0;
	for (; i < MAX_NAME; ++i)
		m_firstName[i] = newFirstName[i];
	m_firstName[i] = '\0';
}

const Contact::t_fixedArr	&Contact::getFirstName(void) const
{
	return this->m_firstName;
}

void		Contact::setLastName(const char newLastName[MAX_NAME])
{
	int		i = 0;
	for (; i < MAX_NAME; ++i)
		m_lastName[i] = newLastName[i];
	m_lastName[i] = '\0';
}

const Contact::t_fixedArr	&Contact::getLastName(void) const
{
	return this->m_lastName;
}

void		Contact::setNickname(const char newNickname[MAX_NAME])
{
	int		i = 0;
	for (; i < MAX_NAME; ++i)
		m_nickname[i] = newNickname[i];
	m_nickname[i] = '\0';
}

const Contact::t_fixedArr	&Contact::getNickname(void) const
{
	return this->m_nickname;
}

void		Contact::setPhoneNumber(const char newPhoneNumber[MAX_NAME])
{
	int		i = 0;
	for (; i < MAX_NAME; ++i)
		m_phoneNumber[i] = newPhoneNumber[i];
	m_phoneNumber[i] = '\0';
}

const Contact::t_fixedArr	&Contact::getPhoneNumber(void) const
{
	return this->m_phoneNumber;
}

void		Contact::setDarkestSecret(const char newDarkestSecret[MAX_NAME])
{
	int		i = 0;
	for (; i < MAX_NAME; ++i)
		m_darkestSecret[i] = newDarkestSecret[i];
	m_darkestSecret[i] = '\0';
}

const Contact::t_fixedArr	&Contact::getDarkestSecret(void) const
{
	return this->m_darkestSecret;
}
