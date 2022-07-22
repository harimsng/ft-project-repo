#include <iostream>

#include "Filehandler.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "invaild arguments.\n";
		std::cout << "miniSed  [filename]  [from]  [to]\n";
		return 1;
	}

	Filehandler	filehandler(argv[2], argv[3]);

	filehandler.openFile(argv[1], ("." + std::string(argv[1]) + ".temp").data());
	filehandler.transformFile();
	filehandler.closeFile();
	if (filehandler.getStatus())
	{
		std::cout << "IO error\n";
		return 1;
	}
	return 0;
}
