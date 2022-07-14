/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/1j 02:26:40 by hseong            #+#    #+#             */
/*   Updated: 2022/07/15 05:44:45 by hseong           ###   ########.fr       */
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

PhoneBook::PhoneBook():
	m_phoneBookStartIdx(0),
	m_phoneBookSize(0)
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
	int		phoneBookIdx;

	if (m_phoneBook.getSize() == MAX_CONTACT)
	{
		std::cout << "Phonebook is full.\n";
		return false;
	}
	std::cout << "input fields to make a contact\n";
	contact = m_phoneBook.m_storage + m_phoneBook.m_start;
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
	contact->setIndex(phoneBookIdx);
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

static void	printInternal(Contact *contact);

bool	PhoneBook::searchContact(void)
{
	int		idx;

	std::cout << "input an index : \n";
	std::cin >> idx;
	if (this->m_phoneBook[idx].getIndex() == -1)
	{
		std::cout << "it's an empty index.\n";
		return false;
	}
	printInternal(this->m_phoneBook + idx);
	return true;
}

static void	printInternal(Contact *contact)
{
	const char	*strPtr;

	std::cout << "|     index|first name| last name|  nickname|\
       TEL|    secret|\n|";
	std::cout.width(10);
	std::cout << contact->getIndex() << '|';
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
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
