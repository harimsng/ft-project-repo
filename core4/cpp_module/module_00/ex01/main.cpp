/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 05:16:56 by hseong            #+#    #+#             */
/*   Updated: 2022/07/17 19:41:47 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ios>
#include <iostream>
#include <limits>

#include "PhoneBook.hpp"

static void	promptInfo(void);

static Contact	g_initialPhonebook[7] = {
	{0, "1234567890", "1234567890", "1234567890", "1234567890", "1234567890"},
	{1, "abcdefghij", "abcdefghij", "abcdefghij", "abcdefghij", "abcdefghij"},
	{2, "0000000000", "0000000000", "0000000000", "0000000000", "0000000000"},
	{3, "1111111111", "1111111111", "1111111111", "1111111111", "1111111111"},
	{4, "2222222222", "2222222222", "2222222222", "2222222222", "2222222222"},
	{5, "3333333333", "3333333333", "3333333333", "3333333333", "3333333333"},
	{6, "4444444444", "4444444444", "4444444444", "4444444444", "4444444444"},
};

int	main(void)
{
	PhoneBook	phoneBook(g_initialPhonebook, 7);
	std::string	inputStr;

	promptInfo();
	while (std::cin.eof() == false)
	{
		std::cout << "> ";
		std::cin.clear();
		std::getline(std::cin, inputStr);
		if (inputStr == "ADD")
			phoneBook.addContact();
		else if (inputStr == "SEARCH")
		{
			phoneBook.showPhoneBook();
			while (phoneBook.searchContact() == false
				&& std::cin.good() == true)
			{
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
					'\n');
			}
		}
		else if (inputStr == "EXIT")
			break;
	}
	return 0;
}

static void	promptInfo(void)
{
	std::cout << "Welcome to phone book service.\n";
	std::cout << "options list\n";
	std::cout << "	ADD - add a contact\n";
	std::cout << "	SEARCH - search a contact with index\n";
	std::cout << "	EXIT - exit program.\n";
}
