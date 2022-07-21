#include <iostream>
#include <string>

int	main(void)
{
	std::string		stringVAR("HI THIS IS BRAIN");
	std::string		*stringPTR(&stringVAR);
	std::string		&stringREF(stringVAR);

	std::cout.setf(std::cout.left);
	std::cout.width(25);
	std::cout << "address of stringVAR = " << &stringVAR << std::endl;
	std::cout.width(25);
	std::cout << "address of stringPTR = " << &stringPTR << std::endl;
	std::cout.width(25);
	std::cout << "address of stringREF = " << &stringREF << std::endl;
	std::cout.width(25);
	std::cout << "value of stringVAR = " << stringVAR << std::endl;
	std::cout.width(25);
	std::cout << "value of stringPTR = " << stringPTR << std::endl;
	std::cout.width(25);
	std::cout << "value of stringREF = " << stringREF << std::endl;
	return 0;
}
