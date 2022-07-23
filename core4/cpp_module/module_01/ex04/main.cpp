#include <iostream>

#include "Substitutor.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "invaild arguments.\n";
		std::cout << "miniSed  [filename]  [from]  [to]\n";
		return 1;
	}

	Substitutor	substitutor(argv[2], argv[3]);

	substitutor.openFile(argv[1]);
	substitutor.transformFile();
	if (substitutor.isFail())
	{
		std::cout << "IO error\n";
		substitutor.closeFile();
		return 1;
	}
	substitutor.closeFile();
	return 0;
}
