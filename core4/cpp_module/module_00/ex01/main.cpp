/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 05:16:56 by hseong            #+#    #+#             */
/*   Updated: 2022/07/15 05:45:15 by hseong           ###   ########.fr       */
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
