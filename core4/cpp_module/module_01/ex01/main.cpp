/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:30:16 by hseong            #+#    #+#             */
/*   Updated: 2022/07/19 16:07:22 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Zombie.hpp"

Zombie	*zombieHorde(int n, std::string name);

static void	setNum(int &num);
static void	setName(std::string &name);

int	main(void)
{
	Zombie		*zombiePtr;
	int			num = 1;
	std::string	name = "John";

	setNum(num);
	if (num < 1)
	{
		std::cout << "invalid range.\n";
		return 1;
	}
	setName(name);
	zombiePtr = zombieHorde(num, name);
	delete[] zombiePtr;
	return 0;
}
//	system("leaks $$");

static void	setNum(int &num)
{
	num = 1;
	std::cout.width(25);
	std::cout.setf(std::cout.left);
	std::cout << "number of zombies";
	std::cout << ": ";
	std::cin >> num;
	if (std::cin.good() || std::cin.eof())
		return;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "failed to read number. default number 1 will be used.\n";
}

static void	setName(std::string &name)
{
	name = "Monster";
	std::cout.width(25);
	std::cout.setf(std::cout.left);
	std::cout << "name of zombie horde";
	std::cout << ": ";
	std::cin >> name;
	if (std::cin.good() || std::cin.eof())
		return;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "failed to read name. default name \"Monster\" will be used.\n";
}
