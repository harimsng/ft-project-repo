#include <iostream>
#include <iomanip>

int	main(void)
{
	std::string str;
	int			idx;

	std::cin >> idx;
	if (std::cin.fail() == true)
	{
		std::cin.clear();
		std::cin >> str;
		std::cout << "str: " << str << std::endl;
	}
	else
		std::cout << "idx: " << idx << std::endl;
}
/*
int	main(void)
{
	std::string str = "1234567890abcdefghij";

	std::cout.width(5);
	std::cout << std::right << "123" << std::endl;
	std::cout.width(5);
	std::cout << std::right << "abc"<< std::endl;
	std::cout.width(5);
	std::cout << std::right << "0123456789"<< std::endl;
}
*/
