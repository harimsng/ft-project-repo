/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 05:16:56 by hseong            #+#    #+#             */
/*   Updated: 2022/07/15 18:48:11 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ios>
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
		std::getline(std::cin, inputStr);
		index = (inputStr == "ADD")
			+ 2 * (inputStr == "SEARCH")
			+ 8 * (inputStr == "EXIT");
		switch (index)
		{
			case 1:
				phoneBook.addContact();
				break;
			case 2:
				while (phoneBook.searchContact() == false
					&& std::cin.good() == true)
					continue;
				break;
			case 8:
				loopFlag = false;
				break;
		}
	}
	return 0;
}
