#include <iostream>

static void	setStringToupper(std::string &str);

int	main(int argc, char *argv[])
{
	std::string	stringTemp;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 0;
	}
	for (int i = 1; i < argc; ++i)
	{
		stringTemp.assign(argv[i]);
		setStringToupper(stringTemp);
		std::cout << stringTemp;
	}
	std::cout << std::endl;
	return 0;
}

static void	setStringToupper(std::string &str)
{
	for (size_t i = 0; i < str.size(); ++i)
		str[i] -= 32 * (str[i] >= 97 && str[i] <= 122);
}
