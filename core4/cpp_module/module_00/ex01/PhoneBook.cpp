/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/1j 02:26:40 by hseong            #+#    #+#             */
/*   Updated: 2022/07/15 18:48:40 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ios>
#include <limits>

#include "PhoneBook.hpp"

static const char 	*g_promptTable[NUM_DATA] = {
	"input a first name : ",
	"input a last name : ",
	"input a nickname : ",
	"input a phone number : ",
	"input the darkest secret : ",
};

PhoneBook::PhoneBook()
:
	m_start(0),
	m_size(0)
{
}

PhoneBook::~PhoneBook()
{
}

/*
 * "this->m_..." OR just "m_..." ?
 */
bool	PhoneBook::addContact(void)
{
	Contact	*contact;
	char	buffer[MAX_NAME] = {0, };

	std::cout << "input fields to make a contact\n";
	if (m_size == MAX_CONTACT)
	{
		std::cout << "WARNING: phone book is full. oldest contact has been removed.\n";
		++m_start;
		--m_size;
	}
	contact = m_phoneBook + (m_start + m_size++) % MAX_CONTACT;
	contact->setIndex((m_start + m_size - 1) % MAX_CONTACT);
	for (int i = 0; i < NUM_DATA; ++i)
	{
		std::cout << g_promptTable[i];
		if (getStringInput(buffer) == false)
		{
			if (std::cin.fail() == false)
			{
				--i;
				continue;
			}
			return false;
		}
		(contact->*(contact->m_setterTable[i]))(buffer);
	}
	return true;
}

/*
 * how to skip the null character in input stream
 * when only a null character were input.
 */
bool	PhoneBook::getStringInput(char str[MAX_NAME])
{
	std::streamsize	count = 0;

	std::cin.getline(str, MAX_NAME);
	count = std::cin.gcount();
	if (count == MAX_NAME - 1)
	{
		std::cout << "ERROR: input string is too long. \
there must be characters less than " << MAX_NAME - 1 << ".\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max()
			, '\n');
		return false;
	}
	else if (count == 1)
	{
		std::cout << "ERROR: there must be input.\n";
		return false;
	}
	if (std::cin.fail() == true)
	{
		std::cout << "\nERROR: an error occured during input.\n";
		return false;
	}
	return true;
}

bool	PhoneBook::searchContact(void)
{
	int		idx;
	int		internalIdx;

	showPhoneBook();
	std::cout << "SEARCH: input an index > \n";
	std::cin.width(10);
	std::cin >> idx;
	if (std::cin.good() == false)
	{
		std::cout << "ERROR: invalid input.\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.clear(std::cin.rdstate() | std::cin.badbit);
		return false;
	}
	if (idx <= 0 || idx > MAX_CONTACT)
	{
		std::cout << "ERROR: invalid range\n";
		return false;
	}
	internalIdx = (m_start + idx - 1) % MAX_CONTACT;
	if (this->m_phoneBook[internalIdx].getIndex() == -1)
	{
		std::cout << "it's an empty index.\n";
		return false;
	}
	std::cout << "|     index|first name| last name|  nickname|\
       TEL|    secret|\n";
	printInternal(this->m_phoneBook + internalIdx);
	return true;
}

void	PhoneBook::printInternal(Contact *contact)
{
	const char	*strPtr;

	std::cout << '|';
	std::cout.width(10);
	std::cout << ((contact->getIndex() - m_start + MAX_CONTACT) % MAX_CONTACT) + 1 << '|';
	for (int i = 0; i < NUM_DATA; ++i)
	{
		strPtr = (contact->*(contact->m_getterTable[i]))();
		int	strLen = 0;
		for (; strPtr[strLen] != '\0'; ++strLen) continue;
		if (strLen > 9)
		{
			std::cout << '.';
			std::cout.write(strPtr + strLen - 9, 9);
		}
		else
		{
			std::cout.width(10);
			std::cout << strPtr;
		}
		std::cout << '|';
	}
	std::cout << std::endl;
}

void	PhoneBook::showPhoneBook(void)
{
	int		internalIdx;

	if (m_size == 0)
		std::cout << "phonebook is empty.\n";
	else
		std::cout << "|     index|first name| last name|  nickname|\
       TEL|    secret|\n";
	for (int i = 0; i < m_size; ++i)
	{
		internalIdx = (i + m_start) % MAX_CONTACT;
		printInternal(this->m_phoneBook + internalIdx);
	}
}
