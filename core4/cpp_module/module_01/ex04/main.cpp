#include "Filehandler.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		return 1;
	}

	Filehandler	filehandler(argv[2], argv[3]);

	filehandler.openFile(argv[1]);
	filehandler.transformFile();
	if (filehandler.getStatus())
	{
		return 1;
	}
	return 0;
}
